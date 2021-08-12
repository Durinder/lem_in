/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:43:47 by vhallama          #+#    #+#             */
/*   Updated: 2021/06/29 15:34:12 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	return_line(char **s, int fd, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	if (s[fd] == NULL)
		return (0);
	while (s[fd][len] != '\0')
	{
		if (s[fd][len] == '\n')
		{
			*line = ft_strsub(s[fd], 0, len);
			tmp = ft_strdup(s[fd] + len + 1);
			ft_strdel(&s[fd]);
			s[fd] = tmp;
			return (1);
		}
		if (s[fd][++len] == '\0')
		{
			*line = ft_strdup(s[fd]);
			ft_strdel(&s[fd]);
			return (1);
		}
	}
	ft_strdel(&s[fd]);
	return (0);
}

static void	assign_buffer(char **s, const int fd, char buf[BUFF_SIZE + 1])
{
	char	*tmp;

	if (s[fd] == NULL)
		s[fd] = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(s[fd], buf);
		ft_strdel(&s[fd]);
		s[fd] = tmp;
	}
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*s[FD_SIZE];

	if (fd == -1 || fd > FD_SIZE || line == NULL)
		return (-1);
	while (1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		else if (ret == 0)
			break ;
		buf[ret] = '\0';
		assign_buffer(s, fd, buf);
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (return_line(s, fd, line));
}

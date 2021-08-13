/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/13 15:52:59 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	next_room_type(const char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (0);
	else if (ft_strcmp(line, "##end") == 0)
		return (2);
	return (1);
}

static int	validate_line(const char *line)
{
	if (line[0] == '\0')
		return (0);
	ft_printf("%s\n", line);
	return (1);
}

void	reader(t_room *maze)
{
	int		ret;
	char	*line;
	char	type;

	ret = 0;
	line = NULL;
	type = 1;
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == 0)
			break ;
		if (ret == -1)
			ft_error_exit("Error");
		if (validate_line(line) == 0)
		{
			free(line);
			ft_error_exit("Error");
		}
		create_room(line, type);
		type = next_room_type(line);
		free(line);
	}
}

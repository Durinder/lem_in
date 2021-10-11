/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:20:07 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 12:37:02 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	int		j;

	if (s)
	{
		j = ft_strlen(s) - start;
		if (j < (int)len && j < 0)
			return (NULL);
		else if (j < (int)len)
			len = j;
		substring = (char *)malloc(len + 1);
		if (substring == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			substring[i] = s[start + i];
			i++;
		}
		substring[i] = '\0';
		return (substring);
	}
	return (NULL);
}

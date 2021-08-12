/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:11:32 by vhallama          #+#    #+#             */
/*   Updated: 2019/10/30 12:50:38 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (s)
	{
		start = 0;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		end = ft_strlen(s);
		while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			end--;
		if (end == 0)
			return (ft_strnew(0));
		return (ft_strsub(s, start, end - start));
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:39:54 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 14:51:47 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*temp_haystack;
	char	*temp_needle;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*needle == *haystack)
		{
			temp_haystack = (char *)haystack;
			temp_needle = (char *)needle;
			while (*temp_haystack++ == *temp_needle++)
			{
				if (*temp_needle == '\0')
					return ((char *)haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}

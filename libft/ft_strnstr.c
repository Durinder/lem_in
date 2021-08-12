/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:56:22 by vhallama          #+#    #+#             */
/*   Updated: 2019/10/31 12:43:47 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*temp_haystack;
	char	*temp_needle;
	size_t	temp_len;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		if (*needle == *haystack)
		{
			temp_haystack = (char *)haystack;
			temp_needle = (char *)needle;
			temp_len = len;
			while (*temp_haystack++ == *temp_needle++ && temp_len-- > 0)
			{
				if (*temp_needle == '\0')
					return ((char *)haystack);
			}
		}
		len--;
		haystack++;
	}
	return (NULL);
}

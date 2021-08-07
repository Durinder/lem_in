/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:45:35 by jhallama          #+#    #+#             */
/*   Updated: 2019/10/30 14:32:35 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		joined_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (joined_string == NULL)
			return (NULL);
		i = 0;
		while (s1[i] != '\0')
		{
			joined_string[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
			joined_string[i++] = s2[j++];
		joined_string[i] = '\0';
		return (joined_string);
	}
	return (NULL);
}

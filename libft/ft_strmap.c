/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:29:59 by jhallama          #+#    #+#             */
/*   Updated: 2019/10/28 14:35:42 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_string;
	size_t	i;

	if (s)
	{
		i = 0;
		new_string = (char *)malloc(ft_strlen(s) + 1);
		if (new_string == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			new_string[i] = f(s[i]);
			i++;
		}
		new_string[i] = '\0';
		return (new_string);
	}
	return (NULL);
}

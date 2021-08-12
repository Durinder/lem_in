/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:15:45 by vhallama          #+#    #+#             */
/*   Updated: 2019/10/28 14:07:59 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			new_string[i] = f(i, s[i]);
			i++;
		}
		new_string[i] = '\0';
		return (new_string);
	}
	return (NULL);
}

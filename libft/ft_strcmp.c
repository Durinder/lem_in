/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:44:36 by jhallama          #+#    #+#             */
/*   Updated: 2019/10/31 13:57:14 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		result;
	size_t	i;

	result = 0;
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}

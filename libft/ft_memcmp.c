/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:55:13 by jhallama          #+#    #+#             */
/*   Updated: 2019/10/24 15:17:07 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*s1_ptr;
	const unsigned char		*s2_ptr;

	i = 0;
	s1_ptr = s1;
	s2_ptr = s2;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return ((int)s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}

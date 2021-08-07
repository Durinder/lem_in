/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:06:45 by jhallama          #+#    #+#             */
/*   Updated: 2019/10/24 14:31:34 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*ptr;

	i = 0;
	ptr = s;
	while (n-- > 0)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

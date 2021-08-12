/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:39:14 by vhallama          #+#    #+#             */
/*   Updated: 2019/10/24 12:35:28 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;

	i = 0;
	d_ptr = dst;
	s_ptr = src;
	while (n-- > 0)
	{
		d_ptr[i] = s_ptr[i];
		if (s_ptr[i++] == (unsigned char)c)
			return (dst + i);
	}
	return (NULL);
}

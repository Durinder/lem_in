/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:39:12 by jhallama          #+#    #+#             */
/*   Updated: 2019/10/24 11:47:43 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d_ptr;
	const char	*s_ptr;

	if (n == 0 || dst == src)
		return (dst);
	d_ptr = dst;
	s_ptr = src;
	while (n-- > 0)
		*d_ptr++ = *s_ptr++;
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:19:28 by vhallama          #+#    #+#             */
/*   Updated: 2019/10/24 14:22:33 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;
	size_t				i;

	d_ptr = dst;
	s_ptr = src;
	i = 0;
	if (len == 0 || dst == src)
		return (dst);
	if (s_ptr < d_ptr)
	{
		while (len-- > 0)
			d_ptr[len] = s_ptr[len];
	}
	else
	{
		while (i < len)
		{
			d_ptr[i] = s_ptr[i];
			i++;
		}
	}
	return (dst);
}

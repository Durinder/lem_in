/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:16:04 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/01 13:17:59 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc_safe(size_t size)
{
	void	*mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
		ft_error_exit("Error: malloc.");
	return (mem);
}

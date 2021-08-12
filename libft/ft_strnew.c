/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:44:48 by vhallama          #+#    #+#             */
/*   Updated: 2019/10/24 15:53:22 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (size + 1 > 0)
	{
		s[size] = '\0';
		size--;
	}
	return (s);
}

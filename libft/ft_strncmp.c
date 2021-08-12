/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:58:02 by vhallama          #+#    #+#             */
/*   Updated: 2019/10/31 14:05:51 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	i;

	result = 0;
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && n-- > 0)
		i++;
	if (n > 0)
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}

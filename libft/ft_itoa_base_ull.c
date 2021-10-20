/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:22:28 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/19 18:08:15 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_chars(unsigned long long n, short counter, char *s,
		short base)
{
	size_t	tmp;

	while (n)
	{
		tmp = n % base;
		if (tmp < 10)
			s[counter--] = tmp + 48;
		else
			s[counter--] = tmp + 87;
		n /= base;
	}
	return (s);
}

static short	count_length(unsigned long long n, short base)
{
	short	len;

	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base_ull(unsigned long long n, short base)
{
	char		*s;
	short		counter;

	if (base == 10)
		return (ft_itoa_ull(n));
	if (n == 0)
	{
		s = ft_strdup("0");
		if (s == NULL)
			return (NULL);
		return (s);
	}
	counter = count_length(n, base);
	s = ft_strnew(counter);
	if (s == NULL)
		return (NULL);
	s = copy_chars(n, --counter, s, base);
	return (s);
}

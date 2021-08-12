/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:02:08 by vhallama          #+#    #+#             */
/*   Updated: 2021/06/29 12:52:10 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_chars(long long n, short counter, char *s, short base)
{
	long long	tmp;

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

static short	count_length(long long n, short base)
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

char	*ft_itoa_base(long long n, short base)
{
	char		*s;
	short		counter;

	if (base == 10)
		return (ft_itoa(n));
	if (n == 0)
	{
		s = ft_strnew(0);
		if (s == NULL)
			return (NULL);
		s[0] = '0';
		return (s);
	}
	counter = count_length(n, base);
	s = ft_strnew(counter);
	if (s == NULL)
		return (NULL);
	if (n < 0)
		n = -n;
	s = copy_chars(n, --counter, s, base);
	return (s);
}

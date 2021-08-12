/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:08:04 by vhallama          #+#    #+#             */
/*   Updated: 2021/06/29 13:15:12 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	decimal_length(long double n)
{
	short	counter;

	counter = 0;
	n -= (long long)n;
	while (n)
	{
		n *= 10;
		counter++;
		n -= (int)n;
	}
	return (counter);
}

static char	*decimal_assignment(long double n)
{
	char		*decimals;
	long long	integers;
	short		counter;

	if (n < 0)
		n = -n;
	counter = decimal_length(n);
	decimals = ft_strnew(counter);
	if (decimals == NULL)
		return (NULL);
	integers = n;
	n -= (long double)integers;
	counter = 0;
	while (n)
	{
		n *= 10;
		decimals[counter++] = (int)n + '0';
		integers = n;
		n -= (int)integers;
	}
	return (decimals);
}

static char	*integer_malloc(long double n, short counter)
{
	char	*integers;

	if (n < 0)
		integers = ft_strnew(counter + 2);
	else
		integers = ft_strnew(counter + 1);
	if (integers == NULL)
		return (NULL);
	return (integers);
}

static char	*integer_assignment(long double n)
{
	long long	nb;
	short		counter;
	char		*integers;

	nb = n;
	counter = ft_nbrlen(nb);
	integers = integer_malloc(n, counter);
	if (integers == NULL)
		return (NULL);
	if (n < 0)
	{
		integers[0] = '-';
		counter++;
		nb = -nb;
	}
	integers[counter--] = '.';
	if (nb == 0)
		integers[counter] = '0';
	while (nb)
	{
		integers[counter--] = nb % 10 + '0';
		nb /= 10;
	}
	return (integers);
}

char	*ft_itoa_float(long double n)
{
	char		*integers;
	char		*result;
	char		*decimals;

	integers = integer_assignment(n);
	decimals = decimal_assignment(n);
	result = ft_strjoin(integers, decimals);
	ft_strdel(&integers);
	ft_strdel(&decimals);
	return (result);
}

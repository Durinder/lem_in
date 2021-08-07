/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:16:57 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/28 18:03:48 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(char *string, long nb, short len)
{
	if (nb == 0)
		string[0] = '0';
	while (nb != 0)
	{
		string[len--] = nb % 10 + 48;
		nb /= 10;
	}
}

static short	count_length(int n)
{
	short	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	long	nb;
	short	len;
	char	*string;

	nb = n;
	len = count_length(nb);
	if (n < 0)
	{
		string = (char *)malloc(len++ + 2);
		if (string == NULL)
			return (NULL);
		string[0] = '-';
		nb = -nb;
	}
	else
	{
		string = (char *)malloc(len + 1);
		if (string == NULL)
			return (NULL);
	}
	string[len--] = '\0';
	convert(string, nb, len);
	return (string);
}

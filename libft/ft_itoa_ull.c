/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:42:00 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 13:29:17 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	count_length(unsigned long long n)
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

char	*ft_itoa_ull(unsigned long long nb)
{
	short	len;
	char	*string;

	len = count_length(nb);
	string = (char *)malloc(len + 1);
	if (string == NULL)
		return (NULL);
	string[len--] = '\0';
	if (nb == 0)
		string[0] = '0';
	while (nb != 0)
	{
		string[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (string);
}

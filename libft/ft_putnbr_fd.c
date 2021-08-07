/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:31:01 by jhallama          #+#    #+#             */
/*   Updated: 2019/10/30 19:16:45 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;

	n_long = n;
	if (n_long < 0)
	{
		ft_putchar_fd('-', fd);
		n_long = -n_long;
	}
	if (n_long > 9)
	{
		ft_putnbr_fd(n_long / 10, fd);
	}
	ft_putchar_fd(n_long % 10 + 48, fd);
}

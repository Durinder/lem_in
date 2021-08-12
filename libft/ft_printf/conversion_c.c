/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:15:16 by vhallama          #+#    #+#             */
/*   Updated: 2021/06/29 15:45:49 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(t_fields *fields, int c)
{
	fields->min--;
	write(1, &c, 1);
	fields->result++;
}

static void	zeroes_and_spaces(t_fields *fields)
{
	if (fields->zero == 1 && fields->minus == 0)
	{
		while (fields->min > 1)
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
	}
	while (fields->minus == 0 && fields->min > 1)
	{
		fields->min--;
		write(1, " ", 1);
		fields->result++;
	}
}

void	conversion_c(t_fields *fields)
{
	int	c;

	c = va_arg(fields->ap, int);
	zeroes_and_spaces(fields);
	print(fields, c);
	if (fields->minus == 1 && fields->zero == 0)
	{
		while (fields->min-- > 0)
		{
			write(1, " ", 1);
			fields->result++;
		}
	}
}

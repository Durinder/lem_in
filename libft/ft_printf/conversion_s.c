/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:40:35 by vhallama          #+#    #+#             */
/*   Updated: 2021/06/29 16:05:49 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(t_fields *fields, char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (fields->precision != 0 && s_len-- > 0)
	{
		fields->min--;
		fields->precision--;
		write(1, s++, 1);
		fields->result++;
	}
}

static void	zeroes_and_spaces(t_fields *fields, char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (fields->zero == 1 && fields->minus == 0)
	{
		while (fields->min - (int)ft_strlen(s) > 0)
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
	}
	if (fields->precision != -1 && fields->precision < s_len)
		s_len = fields->precision;
	while (fields->minus == 0 && fields->min > s_len)
	{
		fields->min--;
		write(1, " ", 1);
		fields->result++;
	}
}

void	conversion_s(t_fields *fields)
{
	char	*s;

	if (fields->prec_astr == 1)
		fields->min = va_arg(fields->ap, int);
	s = va_arg(fields->ap, char *);
	if (s == NULL)
		s = "(null)";
	zeroes_and_spaces(fields, s);
	print(fields, s);
	if (fields->minus == 1)
	{
		while (fields->min-- > 0)
		{
			write(1, " ", 1);
			fields->result++;
		}
	}
}

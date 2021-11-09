/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:57:13 by vhallama          #+#    #+#             */
/*   Updated: 2021/11/09 11:17:52 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(t_fields *fields, char *s)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len-- > 0)
	{
		fields->min--;
		write(1, s++, 1);
		fields->result++;
	}
}

static void	precision_check(t_fields *fields, char *s)
{
	while (fields->precision - (int)ft_strlen(s) > 0)
	{
		fields->precision--;
		write(1, "0", 1);
		fields->result++;
	}
}

static void	zeroes_and_spaces(t_fields *fields, char *s)
{
	if (fields->zero == 1 && fields->minus == 0)
	{
		while (fields->min - (int)ft_strlen(s) > 2)
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
	}
	while (fields->minus == 0 && fields->min - 2 > (int)ft_strlen(s) && \
	fields->min > 2)
	{
		fields->min--;
		write(1, " ", 1);
		fields->result++;
	}
	write(1, "0x", 2);
	fields->result += 2;
}

void	conversion_p(t_fields *fields)
{
	long	n;
	char	*s;

	n = (long)va_arg(fields->ap, void *);
	s = ft_itoa_base(n, 16);
	if (ft_strcmp(s, "0") == 0 && fields->precision == 0)
		s[0] = '\0';
	zeroes_and_spaces(fields, s);
	precision_check(fields, s);
	print(fields, s);
	if (fields->minus == 1)
	{
		while (fields->min-- - 2 > 0)
		{
			write(1, " ", 1);
			fields->result++;
		}
	}
	while (fields->precision != -1 && \
	fields->precision-- - (int)ft_strlen(s) > 0)
	{
		write(1, "0", 1);
		fields->result++;
	}
	ft_strdel(&s);
}

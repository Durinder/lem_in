/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:04:53 by vhallama          #+#    #+#             */
/*   Updated: 2021/11/09 11:15:40 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_and_print(t_fields *fields, char *s, int s_len,
short sign)
{
	if (sign == 1)
	{
		s++;
		s_len--;
	}
	while (fields->precision > s_len)
	{
		fields->precision--;
		fields->min--;
		write(1, "0", 1);
		fields->result++;
	}
	while (s_len--)
	{
		fields->min--;
		write(1, s++, 1);
		fields->result++;
	}
}

static short	additional_sign_and_space_check(t_fields *fields, char *s,
int s_len, short sign)
{
	short	inc;

	inc = 0;
	if (fields->precision == -1)
		inc = 1;
	if (s_len < fields->min)
	{
		if (s[0] == '-' && fields->precision + inc + 1 == fields->min)
		{
			write(1, "-", 1);
			sign = 1;
		}
		else
			write(1, " ", 1);
		fields->min--;
		fields->result++;
	}
	return (sign);
}

static short	left_padding(t_fields *fields, char *s, int s_len, int sign)
{
	short	inc;

	inc = 0;
	if (fields->precision == -1)
		inc = 1;
	while (fields->minus == 0 && fields->min > fields->precision + inc && \
			s_len < fields->min)
	{
		if (fields->zero == 1 && fields->precision == -1)
		{
			while (fields->min > s_len || (s[0] == '-' && fields->min >= s_len))
			{
				fields->min--;
				write(1, "0", 1);
				fields->result++;
			}
		}
		sign = additional_sign_and_space_check(fields, s, s_len, sign);
	}
	return (sign);
}

static short	sign_check(t_fields *fields, char *s, int s_len,
short sign)
{
	if (s[0] == '-' && (s_len >= fields->min || fields->minus == 1 || \
	(fields->zero == 1 && (fields->precision >= fields->min || \
	fields->precision == -1))))
	{
		write(1, "-", 1);
		sign = 1;
		fields->min--;
		fields->result++;
	}
	return (sign);
}

void	conversion_o(t_fields *fields)
{
	char	*s;
	int		s_len;
	short	sign;

	if (fields->min_astr == 1)
		fields->min = va_arg(fields->ap, int);
	if (fields->prec_astr == 1)
		fields->precision = va_arg(fields->ap, int);
	s = choose_type_o(fields);
	s_len = ft_strlen(s);
	sign = 0;
	sign = sign_check(fields, s, s_len, sign);
	sign = left_padding(fields, s, s_len, sign);
	precision_and_print(fields, s, s_len, sign);
	if (fields->minus == 1)
	{
		while (fields->min-- > 0)
		{
			write(1, " ", 1);
			fields->result++;
		}
	}
	ft_strdel(&s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:59:08 by vhallama          #+#    #+#             */
/*   Updated: 2021/06/29 16:38:04 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_and_print(t_fields *fields, char *s, int s_len,
		short sign_check)
{
	if (sign_check == 1)
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
		int s_len, short sign_check)
{
	short	inc;

	inc = 0;
	if (fields->precision == -1)
		inc = 1;
	if (fields->plus == 1 && s[0] != '-' && fields->zero != 1 && (fields->min \
				== fields->precision + inc + 1 || s_len + 1 == fields->min))
	{
		write(1, "+", 1);
		fields->min--;
		fields->result++;
	}
	else if (s_len < fields->min)
	{
		if (s[0] == '-' && fields->precision + inc + 1 == fields->min)
		{
			write(1, "-", 1);
			sign_check = 1;
		}
		else
			write(1, " ", 1);
		fields->min--;
		fields->result++;
	}
	return (sign_check);
}

static short	left_padding(t_fields *fields, char *s, int s_len,
		int sign_check)
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
		sign_check = additional_sign_and_space_check(fields, s, s_len,
				sign_check);
	}
	return (sign_check);
}

static short	sign_and_space_check(t_fields *fields, char *s, int s_len,
		short sign_check)
{
	if (fields->plus == 1 && s[0] != '-' && (s_len >= fields->min || \
				fields->minus == 1 || fields->zero == 1 || \
				fields->precision >= fields->min))
	{
		write(1, "+", 1);
		fields->min--;
		fields->result++;
	}
	else if (s[0] == '-' && (s_len >= fields->min || fields->minus == 1 || \
				fields->precision >= fields->min || (fields->zero == 1 && \
					(fields->precision >= fields->min || \
					fields->precision == -1))))
	{
		write(1, "-", 1);
		sign_check = 1;
		fields->min--;
		fields->result++;
	}
	else if (fields->space == 1 && fields->plus == 0 && s[0] != '-')
	{
		write(1, " ", 1);
		fields->min--;
		fields->result++;
	}
	return (sign_check);
}

void	conversion_di(t_fields *fields)
{
	char	*s;
	int		s_len;
	short	sign_check;

	if (fields->min_astr == 1)
		fields->min = va_arg(fields->ap, int);
	if (fields->prec_astr == 1)
		fields->precision = va_arg(fields->ap, int);
	s = choose_type_di(fields);
	s_len = ft_strlen(s);
	sign_check = 0;
	sign_check = sign_and_space_check(fields, s, s_len, sign_check);
	sign_check = left_padding(fields, s, s_len, sign_check);
	precision_and_print(fields, s, s_len, sign_check);
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

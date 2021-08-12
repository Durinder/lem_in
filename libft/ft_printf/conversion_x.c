/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:11:36 by vhallama          #+#    #+#             */
/*   Updated: 2021/06/29 16:09:04 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_and_print(t_fields *fields, char *s, int s_len)
{
	if (fields->hash == 1 && ft_strcmp(s, "0") != 0)
	{
		write(1, "0x", 2);
		fields->min -= 2;
		fields->result += 2;
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

static void	spaces_and_hash(t_fields *fields, char *s, int s_len)
{
	while (s_len + 2 < fields->min || \
			(s_len < fields->min && ft_strcmp(s, "0") == 0))
	{
		write(1, " ", 1);
		fields->min--;
		fields->result++;
	}
	if (ft_strcmp(s, "0") != 0 && s_len <= fields->min)
	{
		write(1, "0x", 2);
		fields->min -= 2;
		fields->result += 2;
		fields->hash = 0;
	}
}

static void	additional_sign_and_space_check(t_fields *fields, char *s,
		int s_len)
{
	if (s_len < fields->min)
	{
		if (fields->hash == 1)
		{
			spaces_and_hash(fields, s, s_len);
		}
		else
		{
			write(1, " ", 1);
			fields->min--;
			fields->result++;
		}
	}
}

static void	left_padding(t_fields *fields, char *s, int s_len, short inc)
{
	if (fields->precision == -1)
		inc = 1;
	while (fields->minus == 0 && fields->min > fields->precision + inc && \
			s_len < fields->min)
	{
		if (fields->zero == 1 && fields->precision == -1)
		{
			if (fields->hash == 1 && ft_strcmp(s, "0") != 0 && \
					s_len <= fields->min)
			{
				write(1, "0x", 2);
				fields->min -= 2;
				fields->result += 2;
				fields->hash = 0;
			}
			while (fields->min > s_len)
			{
				fields->min--;
				write(1, "0", 1);
				fields->result++;
			}
		}
		additional_sign_and_space_check(fields, s, s_len);
	}
}

void	conversion_x(t_fields *fields)
{
	char	*s;
	int		s_len;

	if (fields->min_astr == 1)
		fields->min = va_arg(fields->ap, int);
	if (fields->prec_astr == 1)
		fields->precision = va_arg(fields->ap, int);
	s = choose_type_x(fields);
	s_len = ft_strlen(s);
	left_padding(fields, s, s_len, 0);
	precision_and_print(fields, s, s_len);
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

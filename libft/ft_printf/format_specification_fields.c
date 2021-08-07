/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specification_fields.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:13:01 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 16:09:30 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*choose_length2(const char *format, t_fields *fields)
{
	if (*format == 'L')
	{
		fields->cap_l = 1;
		format++;
	}
	return (format);
}

const char	*choose_length(const char *format, t_fields *fields)
{
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
		{
			fields->hh = 1;
			format++;
		}
		else
			fields->h = 1;
		format++;
	}
	else if (*format == 'l')
	{
		if (*(format + 1) == 'l')
		{
			fields->ll = 1;
			format++;
		}
		else
			fields->l = 1;
		format++;
	}
	else
		format = choose_length2(format, fields);
	return (format);
}

const char	*choose_width_and_precision(const char *format, t_fields *fields)
{
	if (ft_isdigit(*format) == 1)
		fields->min = ft_atoi(format);
	while (ft_isdigit(*format) == 1)
		format++;
	if (*format == '*')
	{
		fields->min_astr = 1;
		format++;
	}
	if (*format == '.')
	{
		format++;
		if (ft_isdigit(*format) == 1)
			fields->precision = ft_atoi(format);
		else
			fields->precision = 0;
		while (ft_isdigit(*format) == 1)
			format++;
		if (*format == '*')
		{
			fields->prec_astr = 1;
			format++;
		}
	}
	return (format);
}

const char	*choose_flags(const char *format, t_fields *fields)
{
	while (*format == '#' || *format == '0' || *format == '-' || \
			*format == '+' || *format == ' ')
	{
		if (*format == '#')
			fields->hash = 1;
		else if (*format == '0')
			fields->zero = 1;
		else if (*format == '-')
			fields->minus = 1;
		else if (*format == '+')
			fields->plus = 1;
		else if (*format == ' ')
			fields->space = 1;
		format++;
	}
	return (format);
}

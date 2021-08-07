/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:05:49 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 16:10:23 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*choose_conversion(const char *format,
		t_fields *fields)
{
	if (*format == '%')
		conversion_percentage(fields);
	else if (*format == 'c')
		conversion_c(fields);
	else if (*format == 's')
		conversion_s(fields);
	else if (*format == 'p')
		conversion_p(fields);
	else if (*format == 'd')
		conversion_di(fields);
	else if (*format == 'i')
		conversion_di(fields);
	else if (*format == 'o')
		conversion_o(fields);
	else if (*format == 'u')
		conversion_u(fields);
	else if (*format == 'x')
		conversion_x(fields);
	else if (*format == 'X')
		conversion_cap_x(fields);
	else if (*format == 'f')
		conversion_f(fields);
	return (format++);
}

static void	initialize_t_fields(t_fields *fields)
{
	fields->hash = 0;
	fields->zero = 0;
	fields->minus = 0;
	fields->plus = 0;
	fields->space = 0;
	fields->min = -1;
	fields->min_astr = 0;
	fields->dot = 0;
	fields->precision = -1;
	fields->prec_astr = 0;
	fields->hh = 0;
	fields->h = 0;
	fields->l = 0;
	fields->ll = 0;
	fields->cap_l = 0;
}

static void	magic(const char *format, t_fields *fields)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			initialize_t_fields(fields);
			format = choose_flags(format, fields);
			format = choose_width_and_precision(format, fields);
			format = choose_length(format, fields);
			format = choose_conversion(format, fields);
		}
		else
		{
			fields->result++;
			write(1, format, 1);
		}
		if (*format != '\0')
			format++;
	}
}

int	ft_printf(const char *format, ...)
{
	size_t		amount_printed;
	t_fields	*fields;

	if (format == NULL)
		return (0);
	fields = (t_fields *)malloc(sizeof(t_fields));
	if (fields == NULL)
		return (-1);
	fields->result = 0;
	va_start(fields->ap, format);
	magic(format, fields);
	va_end(fields->ap);
	amount_printed = fields->result;
	free(fields);
	return (amount_printed);
}

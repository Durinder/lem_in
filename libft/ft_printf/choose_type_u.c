/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:49:39 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 15:44:41 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*choose_more2(char *s, t_fields *fields)
{
	t_length_type_ouxx	length;

	if (fields->l != 1 && fields->ll != 1 && fields->h != 1 && fields->hh != 1)
	{
		length.unsigned_int_n = va_arg(fields->ap, unsigned int);
		s = ft_itoa_ll(length.unsigned_int_n);
	}
	return (s);
}

static char	*choose_more(char *s, t_fields *fields)
{
	t_length_type_ouxx	length;

	if (fields->h == 1)
	{
		length.unsigned_short_n = va_arg(fields->ap, int);
		s = ft_itoa(length.unsigned_short_n);
	}
	else if (fields->hh == 1)
	{
		length.unsigned_char_n = va_arg(fields->ap, int);
		s = ft_itoa(length.unsigned_char_n);
	}
	s = choose_more2(s, fields);
	return (s);
}

char	*choose_type_u(t_fields *fields)
{
	char				*s;
	t_length_type_ouxx	length;

	s = NULL;
	if (fields->l == 1)
	{
		length.unsigned_long_n = va_arg(fields->ap, unsigned long);
		s = ft_itoa_ull(length.unsigned_long_n);
	}
	else if (fields->ll == 1)
	{
		length.unsigned_long_long_n = va_arg(fields->ap, unsigned long long);
		s = ft_itoa_ull(length.unsigned_long_long_n);
	}
	s = choose_more(s, fields);
	if (ft_strcmp(s, "0") == 0 && fields->precision == 0)
		s[0] = '\0';
	return (s);
}

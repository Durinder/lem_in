/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:14:23 by vhallama          #+#    #+#             */
/*   Updated: 2021/06/29 15:43:53 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*choose_type_f(t_fields *fields)
{
	char	*s;
	char	*s_rounded;
	size_t	i;

	if (fields->cap_l == 1)
		s = ft_itoa_float(va_arg(fields->ap, long double));
	else
		s = ft_itoa_float(va_arg(fields->ap, double));
	s_rounded = ft_float_round(s, fields->precision);
	ft_strdel(&s);
	i = 0;
	while (s_rounded[i] != '.' && s_rounded[i] != '\0')
		i++;
	if (fields->hash == 1 && s_rounded[i] != '.')
	{
		s = ft_strjoin(s_rounded, ".");
		ft_strdel(&s_rounded);
		return (s);
	}
	ft_strdel(&s);
	return (s_rounded);
}

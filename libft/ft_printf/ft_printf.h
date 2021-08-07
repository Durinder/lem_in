/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:02:43 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 16:12:54 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fields {
	va_list	ap;
	size_t	result;

	char	hash;
	char	zero;
	char	minus;
	char	plus;
	char	space;

	int		min;
	char	min_astr;

	char	dot;
	int		precision;
	char	prec_astr;

	char	hh;
	char	h;
	char	l;
	char	ll;
	char	cap_l;
}				t_fields;

typedef struct s_length_type_di {
	long		long_n;
	long long	long_long_n;
	short		short_n;
	signed char	signed_char_n;
	int			int_n;
}				t_length_type_di;

typedef struct s_length_type_ouxx {
	unsigned long		unsigned_long_n;
	unsigned long long	unsigned_long_long_n;
	unsigned short		unsigned_short_n;
	unsigned char		unsigned_char_n;
	unsigned int		unsigned_int_n;
}	t_length_type_ouxx;

int			ft_printf(const char *format, ...);
const char	*choose_flags(const char *format, t_fields *fields);
const char	*choose_width_and_precision(const char *format, t_fields *fields);
const char	*choose_length(const char *format, t_fields *fields);
void		conversion_percentage(t_fields *fields);
void		conversion_c(t_fields *fields);
void		conversion_s(t_fields *fields);
void		conversion_p(t_fields *fields);
void		conversion_di(t_fields *fields);
void		conversion_o(t_fields *fields);
void		conversion_u(t_fields *fields);
void		conversion_x(t_fields *fields);
void		conversion_cap_x(t_fields *fields);
void		conversion_f(t_fields *fields);
char		*choose_type_di(t_fields *fields);
char		*choose_type_o(t_fields *fields);
char		*choose_type_u(t_fields *fields);
char		*choose_type_x(t_fields *fields);
char		*choose_type_cap_x(t_fields *fields);
char		*choose_type_f(t_fields *fields);
#endif

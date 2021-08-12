# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 12:52:05 by vhallama          #+#    #+#              #
#    Updated: 2021/06/29 12:36:26 by vhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTF_SRC = choose_type_di.c choose_type_f.c choose_type_o.c choose_type_u.c choose_type_x.c conversion_c.c conversion_cap_x.c conversion_di.c conversion_f.c conversion_o.c conversion_p.c conversion_percentage.c conversion_s.c conversion_u.c conversion_x.c format_specification_fields.c ft_printf.c

LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_itoa_base.c ft_nbrlen.c ft_itoa_ll.c ft_itoa_ull.c ft_itoa_base_ull.c ft_itoa_float.c ft_float_round.c ft_error_exit.c ft_atoi_l.c 

LIBFT_SRC = $(addprefix ../, $(LIBFT))

HEADERS = ft_printf.h ../libft.h

PRECOMPHEAD = $(addsuffix .gch, $(HEADERS))

PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

LIBFT_OBJ = $(LIBFT:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(LIBFT_SRC) $(PRINTF_SRC) $(HEADERS)
	@ar -rc $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ)
	@ranlib $(NAME)
	@echo "Made libftprintf.a"

clean:
	@/bin/rm -f $(LIBFT_OBJ) $(PRINTF_OBJ) $(PRECOMPHEAD)
	@echo "Cleaned .o and .gch files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Cleaned libraries and binary files"

re: fclean all

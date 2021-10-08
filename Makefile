# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 15:23:07 by vhallama          #+#    #+#              #
#    Updated: 2021/10/08 10:08:00 by vhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(LEM_IN)

LEM_IN = lem_in
LEM_IN_SRC = lem_in.c initialize.c initialize_assigns.c initialize_validating.c free_structs.c graph.c linked_list.c queue.c flags.c flow.c graph_depth.c solver.c
LEM_IN_OBJ = $(LEM_IN_SRC:.c=.o)

LIBRARY = libft/ft_printf/libftprintf.a

FLAGS = -Wall -Wextra -Werror# -fsanitize=address -g

.PHONY: all clean fclean re 

all: $(NAME)

$(LIBRARY):
	@make -C libft/ft_printf/

$(LEM_IN): $(LIBRARY)
	@gcc $(FLAGS) -c $(addprefix src/, $(LEM_IN_SRC))
	@gcc $(FLAGS) -o $(LEM_IN) $(LEM_IN_OBJ) $(LIBRARY)
	@echo "Made lem_in"

clean:
	@make -C libft/ft_printf/ clean
	@rm -f $(LEM_IN_OBJ)
	@echo "Cleaned root .o files"

fclean: clean
	@make -C libft/ft_printf/ fclean
	@rm -f $(LEM_IN)
	@echo "Cleaned root libraries and binary files"

re: fclean all

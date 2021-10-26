# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 15:23:07 by vhallama          #+#    #+#              #
#    Updated: 2021/10/26 15:01:33 by vhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(LEM-IN)

LEM-IN = lem-in
LEM-IN_SRC = lem-in.c initialize.c initialize_assigns.c initialize_validating.c free_structs.c graph.c linked_list.c queue.c flags.c flow.c optimal_routing.c graph_save.c move_ants.c
LEM-IN_OBJ = $(LEM-IN_SRC:.c=.o)

LIBRARY = libft/ft_printf/libftprintf.a

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re 

all: $(NAME)

$(LIBRARY):
	@make -C libft/ft_printf/

$(LEM-IN): $(LIBRARY)
	@gcc $(FLAGS) -c $(addprefix src/, $(LEM-IN_SRC))
	@gcc $(FLAGS) -o $(LEM-IN) $(LEM-IN_OBJ) $(LIBRARY)
	@echo "Made lem-in"

clean:
	@make -C libft/ft_printf/ clean
	@rm -f $(LEM-IN_OBJ)
	@echo "Cleaned root .o files"

fclean: clean
	@make -C libft/ft_printf/ fclean
	@rm -f $(LEM-IN)
	@echo "Cleaned root libraries and binary files"

re: fclean all

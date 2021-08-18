/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:58 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/18 17:34:32 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# define HASH_SIZE 5000

//type == 0 is start, type == 1 is regular room, type == 2 is end

typedef struct s_room {
	char			*name;
	size_t			occupants;
	size_t			weight;
	struct s_room	*next;
}	t_room;

typedef struct s_graph {
	size_t			ants;
	int				total_rooms;
	short			start;
	short			end;
	struct s_room	**adjlists;
}	t_graph;

typedef struct s_init {
	char	*line;
	int		ret;
	int		line_type;
	int		room_type;
}	t_init;

t_graph	*create_graph(int vertices);
t_room	*create_node(char *name);
void	initialize(t_graph *maze);
void	free_graph(t_graph *graph);
void	add_edge(t_graph *graph, char **rooms);
int		connect_to(t_room **adjlists, t_room *new, const char *dest);
//void	insert(t_room **adjlists, t_room *new, const char *name);
#endif
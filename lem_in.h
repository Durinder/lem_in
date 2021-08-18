/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:58 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/18 19:20:34 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# define GRAPH_VERTICES 5000

//type == 0 is start, type == 1 is regular room, type == 2 is end

typedef struct s_room {
	char			*name;
	size_t			occupants;
	size_t			weight;
	struct s_room	*next;
}	t_room;

typedef struct s_graph {
	size_t			ants;
	size_t			total_rooms;
	size_t			start;
	size_t			end;
	struct s_room	**adjlists;
}	t_graph;

typedef struct s_init {
	char	*line;
	int		ret;
	int		start_check;
	int		end_check;
}	t_init;

t_graph	*create_graph(size_t vertices);
t_room	*create_node(char *name);
void	initialize(t_graph *maze);
void	assign_ants(t_graph *graph, t_init *init);
void	assign_rooms(t_graph *graph, t_init *init, size_t i);
void	assign_links(t_graph *graph, t_init *init, size_t i, size_t j);
void	free_graph(t_graph *graph);
void	add_edge(t_graph *graph, char **rooms);
int		connect_to(t_room **adjlists, t_room *new, const char *dest);
//void	insert(t_room **adjlists, t_room *new, const char *name);
#endif
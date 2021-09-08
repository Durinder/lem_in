/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:58 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/08 14:16:56 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"
# define GRAPH_START_SIZE 10

//type == 0 is start, type == 1 is regular room, type == 2 is end

typedef struct s_room {
	char			*name;
	size_t			occupants;
	short			nexts;
	short			prevs;
	struct s_room	**next;
	struct s_room	**prev;
}	t_room;

typedef struct s_graph {
	size_t			ants;
	size_t			total_rooms;
	size_t			start;
	size_t			end;
	struct s_room	**adjlists;
}	t_graph;

typedef struct s_roomlist {
	char				*name;
	struct s_roomlist	*next;
}	t_roomlist;

typedef struct s_init {
	char	*line;
	size_t	ants;
	size_t	total_rooms;
	size_t	start;
	size_t	end;
	int		ret;
	short	start_check;
	short	end_check;
}	t_init;

t_init		get_t_init(void);
t_graph		*initialize(void);
void		assign_ants(t_init *init);
void		assign_rooms(t_init *init, t_roomlist *head, size_t i);
t_roomlist	*create_roomlist_node(char *name);
void		push_back(t_roomlist *head, char *name);
t_graph	*create_graph(t_init init, t_roomlist *head);
//void	realloc_graph(t_graph *graph);
//t_room	*create_node(char *name);
void	assign_links(t_graph *graph, t_init *init, size_t i, size_t j);
void	free_graph(t_graph *graph);
void	add_edge(t_graph *graph, char **rooms);
int		connect_to(t_room **adjlists, t_room *new, const char *dest);
//void	insert(t_room **adjlists, t_room *new, const char *name);
#endif
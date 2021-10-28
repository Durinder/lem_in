/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:58 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/28 16:14:46 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_flags {
	char	path;
	char	lines;
}	t_flags;

typedef struct s_room {
	char			*name;
	struct s_room	*parent;	
	struct s_room	*input;
	struct s_room	*output;
	struct s_room	**link;
	int				ant;
	int				links;
	int				depth;
	int				load;
	int				visited;
}	t_room;

typedef struct s_save {
	struct s_room	*input;
	struct s_room	*output;
	int				load;
}	t_save;

typedef struct s_queue_node {
	struct s_room		*room;
	struct s_room		*only_dir;
	struct s_queue_node	*next;
}	t_queue_node;

typedef struct s_queue {
	struct s_queue_node	*front;
	struct s_queue_node	*rear;
}	t_queue;

typedef struct s_graph {
	int				ants;
	int				total_rooms;
	int				start;
	int				end;
	struct s_room	**list;
}	t_graph;

typedef struct s_init {
	struct s_roomlist	*head;
	char				*line;
	int					ants;
	int					total_rooms;
	int					start;
	int					end;
	int					ret;
	char				start_check;
	char				end_check;
	char				comment_check;
}	t_init;

typedef struct s_roomlist {
	char				*name;
	int					xy[2];
	struct s_roomlist	*next;
}	t_roomlist;

t_graph		*initialize(void);
t_roomlist	*create_roomlist_node(char *name, int *xy);
void		assign_ants(t_init *init);
void		assign_rooms(t_init *init, int i);
int			*validate_coordinates(t_init *init, int i);
void		push_back_roomlist(t_roomlist **head, char *name, int *xy);
void		validate_start_and_end(t_init *init);
t_graph		*create_graph(t_init *init);
void		assign_links(t_graph *graph, t_init *init, t_room *room1,
				t_room *room2);
t_room		*find_and_validate_room(t_graph *graph, t_init *init, int j,
				short which);
void		check_if_link_exists(t_room *room1, t_room *room2);
void		add_edge(t_room *room1, t_room *room2);
void		free_graph(t_graph *graph);
void		free_init(t_init *init);
t_queue		*create_queue(void);
void		enqueue(t_queue *queue, t_room *room, t_room *only_dir);
void		enqueue_front(t_queue *queue, t_room *room, t_room *only_dir);
t_room		*dequeue(t_queue *queue, t_room **only_dir);
char		is_empty(t_queue *queue);
void		free_queue(t_queue *queue);
void		delete_queue(t_queue *queue);
t_flags		*assign_flags(int argc, char **argv);
void		print_pathing(t_room *start);
void		max_flow(t_graph *graph, t_flags *flags);
void		save_best_routing(t_save **save, t_graph *graph);
t_save		**create_save(int rooms);
void		save_state(t_save **cpy, t_room **src, int rooms);
void		fetch_save(t_room **dst, t_save **save, int rooms);
void		free_save(t_save **save, int rooms);
void		move_ants(t_graph *graph);
#endif
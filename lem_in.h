/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:58 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/17 15:02:31 by vhallama         ###   ########.fr       */
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
	short			type;
	struct s_room	*next;
}	t_room;

typedef struct s_graph {
	int				total_rooms;
	struct s_room	**adjlists;
}	t_graph;

typedef struct s_reader {
	char	*line;
	int		ret;
	int		line_type;
	int		room_type;
}	t_reader;

void	reader(t_graph *maze);
void	add_edge(t_graph *graph, char **rooms);
int		connect_to(t_room **adjlists, t_room *new, const char *dest);
//void	insert(t_room **adjlists, t_room *new, const char *name);
#endif
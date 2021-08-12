/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:58 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/12 15:22:59 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

//type == 0 is start, type == 1 is regular room, type == 2 is end

typedef struct s_room {
	char			*name;
	size_t			occupants;
	size_t			weight;
	short			type;
	struct s_room	*next;
}	t_room;

typedef struct s_adjlist {
	size_t			total_rooms;
	struct s_room	**array;
}	t_adjlist;

/* #define SIZE 20

struct DataItem {
   int data;   
   int key;
};
 */

void	reader(t_room *maze);
#endif
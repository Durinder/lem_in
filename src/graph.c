/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 15:07:38 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	realloc_links(t_room *room)
{
	t_room	**new;
	int		i;

	new = ft_malloc_safe(sizeof(t_room *) * room->links);
	if (room->links > 1)
	{
		i = 0;
		while (i < room->links - 1)
		{
			new[i] = room->link[i];
			i++;
		}
		free(room->link);
	}
	room->link = new;
}

void	add_edge(t_room *room1, t_room *room2)
{
	room1->links++;
	realloc_links(room1);
	room1->link[room1->links - 1] = room2;
	room2->links++;
	realloc_links(room2);
	room2->link[room2->links - 1] = room1;
}

static t_room	*create_room_node(char *name, int i, t_init *init)
{
	t_room	*new;

	new = ft_malloc_safe(sizeof(t_room));
	new->name = name;
	if (i == init->start)
		new->ant = 1;
	else
		new->ant = 0;
	return (new);
}

static void	create_rooms(t_graph *graph, t_init *init)
{
	t_roomlist	*cur;
	int			i;

	i = 0;
	cur = init->head;
	while (cur != NULL)
	{
		graph->list[i] = create_room_node(cur->name, i, init);
		cur = cur->next;
		i++;
	}
}

t_graph	*create_graph(t_init *init)
{
	t_graph	*graph;

	graph = ft_malloc_safe(sizeof(t_graph));
	graph->ants = init->ants;
	graph->total_rooms = init->total_rooms;
	graph->start = init->start;
	graph->end = init->end;
	graph->list = ft_malloc_safe(sizeof(t_room *) * init->total_rooms);
	create_rooms(graph, init);
	return (graph);
}

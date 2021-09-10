/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/10 15:34:59 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

//which == 0 is room->child realloc, which == 1 is room->parent realloc
static void	realloc_room(t_room *room, short which, size_t i)
{
	t_room	**new;

	if (which == 0)
	{
		new = ft_malloc_safe(sizeof(t_room **) * room->child_amount);
		while (i < room->child_amount - 1)
		{
			new[i] = room->child[i];
			i++;
		}
		free(room->child);
		room->child = new;
	}
	else
	{
		new = ft_malloc_safe(sizeof(t_room **) * room->parent_amount);
		while (i < room->parent_amount - 1)
		{
			new[i] = room->parent[i];
			i++;
		}
		free(room->parent);
		room->parent = new;
	}
}

void	add_edge(t_room *src, t_room *dst)
{
	src->child_amount++;
	if (src->child == NULL)
		src->child = ft_malloc_safe(sizeof(t_room **));
	else
		realloc_room(src, 0, 0);
	dst->parent_amount++;
	if (dst->parent == NULL)
		dst->parent = ft_malloc_safe(sizeof(t_room **));
	else
		realloc_room(dst, 1, 0);
	src->child[src->child_amount - 1] = dst;
	dst->parent[dst->parent_amount - 1] = src;
}

static t_room	*create_room_node(char *name, size_t i, t_init *init)
{
	t_room	*new;

	new = ft_malloc_safe(sizeof(t_room));
	new->name = name;
	if (i == init->start)
		new->occupants = init->ants;
	else
		new->occupants = 0;
	new->child_amount = 0;
	new->parent_amount = 0;
	new->child = NULL;
	new->parent = NULL;
	return (new);
}

/* void	realloc_graph(t_graph *graph)
{
	t_room	**new_list;
	size_t	new_size;
	size_t	i;

	new_size = graph->total_rooms + GRAPH_START_SIZE;
	new_list = ft_malloc_safe(sizeof(t_room *) * new_size);
	i = 0;
	while (i < graph->total_rooms)
	{
		new_list[i] = graph->adjlists[i];
		i++;
	}
	while (i < new_size)
		new_list[i++] = NULL;
	free(graph->adjlists);
	graph->adjlists = new_list;
}
 */
static void	create_rooms_and_free_roomlist(t_graph *graph, t_init *init)
{
	t_roomlist	*cur;
	size_t		i;

	i = 0;
	cur = init->head;
	while (cur != NULL)
	{
		graph->adjlists[i] = create_room_node(cur->name, i, init);
		cur = cur->next;
//		free(tmp);
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
	graph->adjlists = ft_malloc_safe(sizeof(t_room *) * init->total_rooms);
	create_rooms_and_free_roomlist(graph, init);
	return (graph);
}

/* void	add_edge(t_graph *graph, char **rooms)
{
	t_room	*new;
	int		index;

	if (rooms[0] == NULL || rooms[1] == NULL)
		ft_error_exit("Error: malloc.");
	new = create_node(rooms[1]);
	index = connect_to(graph->adjlists, new, rooms[0]);
	graph->adjlists[index] = new;
	new = create_node(rooms[0]);
	index = connect_to(graph->adjlists, new, rooms[1]);
	graph->adjlists[index] = new;
	free(rooms[2]);
	free(rooms);
} */

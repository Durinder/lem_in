/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/08 14:04:23 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* void	add_edge(t_graph *graph, char *src, char *dst)
{
	t_room	*cur;

	while (cur->next != NULL)
		cur = cur->next;
	cur->next = create_node(ft_strdup(name));
}
 */
static t_room	*create_room_node(char *name)
{
	t_room	*new;

	new = ft_malloc_safe(sizeof(t_room));
	new->name = name;
	new->occupants = 0;
	new->nexts = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	realloc_graph(t_graph *graph)
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

static void	create_rooms_and_free_roomlist(t_graph *graph, t_roomlist *head)
{
	t_roomlist	*tmp;
	size_t		i;

	i = 0;
	while (head != NULL)
	{
		graph->adjlists[i] = create_room_node(head->name);
		tmp = head;
		head = head->next;
		free(tmp);
		i++;
	}
}

t_graph	*create_graph(t_init init, t_roomlist *head)
{
	t_graph	*graph;

	graph = ft_malloc_safe(sizeof(t_graph));
	graph->ants = init.ants;
	graph->total_rooms = init.total_rooms;
	graph->start = init.start;
	graph->end = init.end;
	graph->adjlists = ft_malloc_safe(sizeof(t_room *) * init.total_rooms);
	create_rooms_and_free_roomlist(graph, head);
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

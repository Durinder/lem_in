/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_split_connections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:18:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/17 15:34:34 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* static void	free_connections(t_room *room)
{
	size_t	i;

	i = 0;
	ft_printf("%s\n", room->name);
	while (i < room->connections)
	{
		free(room->connection[i]);
		i++;
	}
	free(room->connection);
	room->connections = 0;
} */

static t_room	**realloc_section(t_room **section, size_t elems)
{
	t_room	**new;
	size_t	i;

	new = ft_malloc_safe(sizeof(t_room **) * elems);
	i = 0;
	while (i < elems - 1)
	{
		new[i] = section[i];
		free(section[i]);
		i++;
	}
	free(section);
	return (new);
}

static void	assign_relationship(t_room *room1, t_room *room2)
{
	room1->child_amount++;
	if (room1->child_amount == 1)
		room1->child = ft_malloc_safe(sizeof(t_room *));
	else
		room1->child = realloc_section(room1->child, room1->child_amount);
	room1->child[room1->child_amount - 1] = room2;
	room2->parent_amount++;
	if (room2->parent_amount == 1)
		room2->parent = ft_malloc_safe(sizeof(t_room *));
	else
		room2->parent = realloc_section(room2->parent, room2->parent_amount);
	room2->parent[room2->parent_amount - 1] = room1;
}

static void	bfs(t_graph *graph, t_queue *q, t_room *room)
{
	t_room	*cur;
	size_t	i;

	i = 0;
	while (i < room->connections)
	{
		assign_relationship(room, room->connection[i]); // KAIKKI CONNECTIONIT ON CHILDEJA!
		enqueue(q, room->connection[i]);
		i++;
	}
	free_connections(room);
	cur = dequeue(q);
	if (cur)
		bfs(graph, q, cur);
	else
		ft_printf("done?\n");
}

void	split_connections_to_childs_and_parents(t_graph *graph)
{
	t_queue	*q;

	q = create_queue();
	bfs(graph, q, graph->adjlists[graph->start]);
}

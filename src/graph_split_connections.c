/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_split_connections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:18:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/21 13:19:49 by vhallama         ###   ########.fr       */
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
/* 
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
 */
/* static void	assign_parent(t_room *child_room, t_room *parent_room)
{
	t_room	**parent;
	size_t	i;

	child_room->parent_amount++;
	parent = ft_malloc_safe(sizeof(t_room *) * child_room->parent_amount);
	if (child_room->parent == NULL)
	{
		child_room->parent = parent;
		child_room->parent[0] = parent_room;
	}
	else
	{
		i = 0;
		while (i < child_room->parent_amount - 1)
		{
			parent[i] = child_room->parent[i];
			i++;
		}
		parent[i] = parent_room;
		free(child_room->parent);
		child_room->parent = parent;
	}
}

static void	restructure_child_room_connection(t_room *child_room,
t_room *parent_room)
{
	size_t	i;

	if (child_room->connection == NULL)
		return ;
	i = 0;
	while (i < child_room->connections)
	{
		if (child_room->connection[i] == parent_room)
			break ;
		i++;
	}
	while (i < child_room->connections - 1)
	{
		child_room->connection[i] = child_room->connection[i + 1];
		i++;
	}
	child_room->connection[i] = NULL;
	child_room->connections--;
}

static void	bfs(t_graph *graph, t_queue *q, t_room *room)
{
	t_room	*cur;
	t_room	**child;
	size_t	i;

	i = 0;
	if (room->connections)
	{
		child = ft_malloc_safe(sizeof(t_room *) * room->connections);
		room->child = child;
		while (i < room->connections)
		{
			room->child[i] = room->connection[i];
			room->child_amount++;
			enqueue(q, room->child[i]);
			restructure_child_room_connection(room->connection[i], room);
			assign_parent(room->connection[i], room);
			i++;
		}
		free(room->connection);
	}
	cur = dequeue(q);
	if (cur)
		bfs(graph, q, cur);
	else
		ft_printf("done?\n");
} */

static void	print_depth(t_graph *graph)
{
	size_t	i;

	i = 0;
	while (i < graph->total_rooms)
	{
		ft_printf("%s->depth(%ld)\n", graph->adjlists[i]->name, graph->adjlists[i]->depth);
		i++;
	}
}

static void	set_depth(t_room *room, t_queue *q, size_t depth)
{
	t_room	*next;
	size_t	i;

	ft_printf("%s, %ld\n", room->name, depth);
	if (room->depth > depth)
		room->depth = depth;
	i = 0;
	while (i < room->connections)
	{
		if (room->connection[i]->visited < room->connection[i]->connections)
		{
			enqueue(q, room->connection[i], depth + 1);
			room->connection[i]->visited++;
		}
		i++;
	}
	next = dequeue(q, &depth);
	if (next)
		set_depth(next, q, depth);
}

void	split_connections_to_childs_and_parents(t_graph *graph)
{
	t_queue	*q;

	q = create_queue();
	set_depth(graph->adjlists[graph->start], q, 0);
	free(q);
	print_depth(graph);
//	bfs(graph, q, graph->adjlists[graph->start]);
}

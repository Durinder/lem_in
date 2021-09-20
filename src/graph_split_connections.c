/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_split_connections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:18:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/20 16:35:55 by vhallama         ###   ########.fr       */
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

static void	set_room_depth(t_room *room)
{
	size_t	i;
	size_t	min;

	i = 0;
	min = UINT_MAX;
	while (i < room->connections)
	{
		if (min > room->depth_options[i])
			min = room->depth_options[i];
		i++;
	}
	room->depth = min;
}

static void	set_room_depth_option(t_room *room, t_room *prev, size_t depth)
{
	size_t	i;

	i = 0;
	while (i < room->connections)
	{
		if (room->connection[i] == prev)
		{
			room->depth_options[i] = depth;
			return ;
		}
		i++;
	}
}

static void	check_room_depth(t_room *room, t_room *prev, size_t depth)
{
	size_t	i;

	i = 0;
	if (room->depth == 0)
	{
		if (prev == NULL)
		{
			room->depth = depth;
			return ;
		}
		if (room->depth_options == NULL)
		{
			room->depth_options = ft_malloc_safe(sizeof(size_t) * \
			room->connections);
			return ;
		}
		while (i < room->connections)
		{
			if (room->depth_options[i] == 0)
			{
				if (room->connection[i] == prev)
					set_room_depth_option(room, prev, depth);
				else
					break ;
			}
			i++;
		}
		if (i == room->connections)
		{
			set_room_depth(room);
			free(room->depth_options);
		}
	}	
}

static void	set_graph_depth(t_room *room, t_room *prev, t_queue *q,
size_t depth)
{
/* 	t_room	*next;
 */	size_t	i;

	check_room_depth(room, prev, depth);
	i = 0;
	while (i < room->connections)
	{
		if (room->connection[i]->depth == 0)
		{
			set_graph_depth(room->connection[i], room, q, depth + 1);//(q, room->connection[i]);
		}
		i++;
	}
/* 	next = dequeue(q);
	if (next)
		set_graph_depth(next, room, q, depth); */
}

/* 
static void	set_room_depth(t_room *start)
{
	t_queue	*q;
	t_room	*cur;
	size_t	i;
	size_t	depth;

	q = create_queue();
	start->visited = 1;
	start->depth = 0;
	depth = 0;
	enqueue(q, start);
	while (is_empty(q) == 0)
	{
		cur = dequeue(q);
		depth++;
		i = 0;
		while (i < cur->connections)
		{
			if (cur->connection[i]->visited == 0)
			{
				cur->connection[i]->depth = depth;
				cur->connection[i]->visited = 1;
				enqueue(q, cur->connection[i]);
			}
			i++;
		}
	}
}
 */
void	split_connections_to_childs_and_parents(t_graph *graph)
{
	t_queue	*q;

	q = create_queue();

//		LOOPPAA AINA VIEREISIA PAITSI, JOS NIIDEN VISITED == CONNECTIONS
//		JOKA KERTA KATSO JOS ROOM->DEPTH(JOKA ALUKSI UINT_MAX) > DEPTH,
//			JOS ON NIIN ROOM->DEPTH = DEPTH;


	set_graph_depth(graph->adjlists[graph->start], NULL, q, 1);
	print_depth(graph);
//	bfs(graph, q, graph->adjlists[graph->start]);
}

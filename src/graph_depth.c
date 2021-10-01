/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_depth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:18:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/01 16:25:05 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

static void	sort_connection_array(t_room *room)
{
	t_room	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < room->connections)
	{
		j = i + 1;
		while (j < room->connections)
		{
			if (room->connection[i]->depth > room->connection[j]->depth)
			{
				tmp = room->connection[i];
				room->connection[i] = room->connection[j];
				room->connection[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	sort_depth(t_graph *graph)
{
	size_t	i;

	i = 0;
	while (i < graph->total_rooms)
	{
		sort_connection_array(graph->adjlists[i]);
		i++;
	}
}

static void	set_depth(t_room *room, t_queue *q, size_t depth)
{
	t_room	*next;
	size_t	i;

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

void	assign_depth(t_graph *graph)
{
	t_queue	*q;

	q = create_queue();
	set_depth(graph->adjlists[graph->end], q, 0);
	if (graph->adjlists[graph->start]->depth == ULONG_MAX)
		ft_error_exit("Error: map cannot be solved.");
	free_queue(q);
	sort_depth(graph);
	print_depth(graph);
}

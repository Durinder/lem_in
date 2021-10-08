/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_depth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:18:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/08 10:06:45 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_depth(t_graph *graph)
{
	int	i;

	write(1, "\n", 1);
	i = 0;
	while (i < graph->total_rooms)
	{
		ft_printf("%s->depth(%ld), %ld\n", graph->adjlists[i]->name, \
		graph->adjlists[i]->depth);
		i++;
	}
}

static void	sort_connection_array(t_room *room)
{
	t_room	*tmp;
	int		i;
	int		j;

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
	int	i;

	i = 0;
	while (i < graph->total_rooms)
	{
		sort_connection_array(graph->adjlists[i]);
		i++;
	}
}

static void	set_room_depth(t_graph *graph, t_queue *q)
{
	t_room	*cur;
	int		depth;
	int		i;

	enqueue(q, graph->adjlists[graph->end], 0);
	graph->adjlists[graph->end]->visited = 1;
	while (!is_empty(q))
	{
		cur = dequeue(q, &depth);
		if (cur->depth > depth)
			cur->depth = depth;
		i = 0;
		if (cur != graph->adjlists[graph->start])
		{
			while (i < cur->connections)
			{
				if (cur->connection[i]->visited == 0)
				{
					enqueue(q, cur->connection[i], depth + 1);
					cur->connection[i]->visited = 1;
				}
				i++;
			}
		}
	}
}

void	assign_depth(t_graph *graph, t_flags *flags)
{
	t_queue	*q;

	set_room_depth(graph, q = create_queue());
	free_queue(q);
	if (graph->adjlists[graph->start]->depth == INT_MAX)
		ft_error_exit("Error: map cannot be solved.");
	sort_depth(graph);
	if (flags)
	{
		if (flags->depth)
			print_depth(graph);
	}
//	create_edges(graph);
}

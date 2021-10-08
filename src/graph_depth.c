/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_depth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:18:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/08 12:59:08 by vhallama         ###   ########.fr       */
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
		ft_printf("%s->depth(%ld), %ld\n", graph->list[i]->name, \
		graph->list[i]->depth);
		i++;
	}
}

static void	sort_link_array(t_room *room)
{
	t_room	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < room->links)
	{
		j = i + 1;
		while (j < room->links)
		{
			if (room->link[i]->depth > room->link[j]->depth)
			{
				tmp = room->link[i];
				room->link[i] = room->link[j];
				room->link[j] = tmp;
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
		sort_link_array(graph->list[i]);
		i++;
	}
}

static void	set_room_depth(t_graph *graph, t_queue *q)
{
	t_room	*cur;
	int		depth;
	int		i;

	enqueue(q, graph->list[graph->end], 0);
	graph->list[graph->end]->visited = 1;
	while (!is_empty(q))
	{
		cur = dequeue(q, &depth);
		if (cur->depth > depth)
			cur->depth = depth;
		i = 0;
		if (cur != graph->list[graph->start])
		{
			while (i < cur->links)
			{
				if (cur->link[i]->visited == 0)
				{
					enqueue(q, cur->link[i], depth + 1);
					cur->link[i]->visited = 1;
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
	if (graph->list[graph->start]->depth == INT_MAX)
		ft_error_exit("Error: map cannot be solved.");
	sort_depth(graph);
	if (flags)
	{
		if (flags->depth)
			print_depth(graph);
	}
//	create_edges(graph);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:07 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/25 14:29:40 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	insert_sort(t_room *room)
{
	t_room	*tmp;
	int		i;
	int		min_i;
	int		sorted_i;

	i = 0;
	min_i = 0;
	sorted_i = 0;
	while (sorted_i + 1 < room->links)
	{
		if (room->link[i]->depth < room->link[min_i]->depth)
			min_i = i;
		i++;
		if (i == room->links)
		{
			tmp = room->link[sorted_i];
			room->link[sorted_i] = room->link[min_i];
			room->link[min_i] = tmp;
			sorted_i++;
			i = sorted_i;
			min_i = sorted_i;
		}
	}
}

static int	calculate_printing_line_amount(t_graph *graph, t_room *start)
{
	int	remaining;
	int	i;

	insert_sort(graph->list[graph->start]);
	remaining = graph->ants;
	i = 0;
	while (remaining > 0)
	{
		if (i + 1 < start->links)
		{
			if (start->link[i]->load + start->link[i]->depth > \
			start->link[i + 1]->load + start->link[i + 1]->depth)
				i++;
			else
				i = 0;
		}
		else
			i = 0;
		start->link[i]->load++;
		remaining--;
	}
	return (start->link[i]->load + start->link[i]->depth);
}

static void	reset_load(t_room *start)
{
	int	i;

	i = 0;
	while (i < start->links)
	{
		start->link[i]->load = 0;
		i++;
	}
}

static void	set_depth_for_paths(t_graph *graph)
{
	t_room	*cur;
	int		depth;
	int		i;

	i = 0;
	while (i < graph->list[graph->end]->links)
	{
		if (graph->list[graph->end]->link[i]->output)
		{
			cur = graph->list[graph->end]->link[i];
			depth = 1;
			while (cur != graph->list[graph->start])
			{
				cur->depth = depth++;
				cur = cur->input;
			}
		}
		i++;
	}
}

void	save_optimal_routing(t_save **save, t_graph *graph)
{
	static int	record;
	int			lines;

	set_depth_for_paths(graph);
	reset_load(graph->list[graph->start]);
	lines = calculate_printing_line_amount(graph, graph->list[graph->start]);
	if (lines < record || record == 0)
	{
		record = lines;
		save_state(save, graph->list, graph->total_rooms);
	}
}

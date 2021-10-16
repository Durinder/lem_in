/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:07 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/16 13:23:07 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	sort_start_links(t_room *start)
{
	t_room	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i + 1 < start->links)
	{
		j = i + 1;
		while (j < start->links)
		{
			if (start->link[i]->depth > start->link[j]->depth)
			{
				tmp = start->link[i];
				start->link[i] = start->link[j];
				start->link[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	calculate_printing_line_amount(t_graph *graph)
{
	int	paths;
	int	highest_depth;
	int	ants_to_highest;
	int	i;

	highest_depth = 0;
	paths = 0;
	i = 0;
	sort_start_links(graph->list[graph->start]);
	while (i < graph->list[graph->start]->links)
	{
		if (graph->list[graph->start]->link[i]->input)
		{
			if (graph->list[graph->start]->link[i]->depth > highest_depth)
				highest_depth = graph->list[graph->start]->link[i]->depth;
			paths++;
		}
		i++;
	}
	ants_to_highest = graph->ants / paths;
	i = graph->ants % paths;
	if (highest_depth > graph->list[graph->start]->link[i]->depth)
		return (ants_to_highest + highest_depth - 1);
	else
		return (ants_to_highest + highest_depth);
}

void	calculate_optimal_routing_to_cpy(t_room ***cpy, t_graph *graph)
{
	static int	record;
	int			lines;

	lines = calculate_printing_line_amount(graph);
	if (lines < record || record == 0)
	{
		record = lines;
		if (*cpy == NULL)
			*cpy = duplicate_list(graph->list, graph->total_rooms);
		else
			copy_list(*cpy, graph->list, graph->total_rooms);
	}
}

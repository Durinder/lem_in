/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:07 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/22 17:31:41 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* static void test_sort(t_room *start)
{
	int	i = 0;

	while (i < start->links)
	{
		ft_printf("%s[%d]->(%d), ", start->link[i]->name, i, start->link[i]->depth);
		i++;
	}
	ft_putchar('\n');
} */

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

void	save_optimal_routing(t_save **save, t_graph *graph)
{
	static int	record;
	int			lines;

	reset_load(graph->list[graph->start]);
	lines = calculate_printing_line_amount(graph, graph->list[graph->start]);
	if (lines < record || record == 0)
	{
		record = lines;
		save_state(save, graph->list, graph->total_rooms);
	}
	ft_printf("lines:%d\n", lines);
}

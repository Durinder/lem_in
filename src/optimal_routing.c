/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:07 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/17 15:53:59 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* 
static void	test(t_graph *graph)
{
	t_room	*start = graph->list[graph->start];
	int	i;

	i = 0;
	while (i < start->links)
	{
		if (start->link[i]->input == NULL)
			break ;
		ft_putstr(start->link[i]->name);
		ft_putchar(',');
		i++;
	}
	ft_putchar('\n');
}
 */
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

static int	calculate_printing_line_amount(t_graph *graph)
// KORJAA EDELLISET LOADIT
{
	t_room	*start;
	int		remaining;
	int		i;

	insert_sort(graph->list[graph->start]);
	start = graph->list[graph->start];
	start->link[0]->load = 1;
	remaining = graph->ants - 1;
	i = 0;
	while (remaining > 0 && i + 1 < start->links)
	{
		while (start->link[i]->load + start->link[i]->depth < \
		start->link[i + 1]->depth)
		{
			start->link[i]->load++;
			remaining -= i + 1;
			if (remaining <= 0)
				return (start->link[i]->load + start->link[i]->depth + 1);
		}
		i++;
	}
	while (remaining > 0)
	{
		start->link[i]->load++;
		remaining -= i + 1;
	}
	return (start->link[i]->load + start->link[i]->depth + 1);
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
	ft_printf("record:%d\n", record);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:51:27 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/25 14:31:03 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	assign_whitespace(t_room *src)
{
	static int	prev_ant;

	if (prev_ant == 0)
		prev_ant = 1;
	if (src->ant <= prev_ant)
		write(1, "\n", 1);
	else
		write(1, " ", 1);
	prev_ant = src->ant;
}

static void	move_ant(t_graph *graph, t_room *dst, t_room *src)
{
	assign_whitespace(src);
	write(1, "L", 1);
	ft_putnbr(src->ant);
	write(1, "-", 1);
	ft_putstr(dst->name);
	if (dst == graph->list[graph->end])
		dst->ant++;
	else
		dst->ant = src->ant;
	if (src == graph->list[graph->start] && src->ant + 1 <= graph->ants)
		src->ant++;
	else
		src->ant = 0;
}

static void	loop(t_graph *graph, t_queue *q, t_room *cur)
{
	int		i;

	while (!is_empty(q))
	{
		cur = dequeue(q, NULL);
		if (cur->output)
		{
			move_ant(graph, cur->output, cur);
			if (cur->output != graph->list[graph->end])
				enqueue(q, cur->output, NULL);
		}
		i = -1;
		while (cur->ant && ++i < cur->links)
		{
			if (cur->link[i]->load)
			{
				move_ant(graph, cur->link[i], cur);
				cur->link[i]->load--;
				if (cur->link[i] != graph->list[graph->end])
					enqueue(q, cur->link[i], NULL);
			}
		}
		if (cur->ant)
			enqueue(q, cur, NULL);
	}
}

void	move_ants(t_graph *graph)
{
	t_queue	*q;

	q = create_queue();
	enqueue(q, graph->list[graph->start], NULL);
	loop(graph, q, NULL);
	write(1, "\n", 1);
	free_queue(q);
}

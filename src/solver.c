/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/02 14:58:05 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* static void	print_queue(t_queue *q) //POISTA JA MYOS BUFFER!!
{
	t_queue_node	*cur;

	cur = q->front;
	while (cur != NULL)
	{
		ft_printf("%s,", cur->room->name);
		cur = cur->next;
	}
	ft_printf("\n");
}
 */
static void	assign_whitespace(t_room *src)
{
	static size_t	prev_ant;

	if (prev_ant == 0)
		prev_ant = 1;
	if (src->ant <= prev_ant)
		write(1, "\n", 1);
	else
		write(1, " ", 1);
	prev_ant = src->ant;
}

static void	move_ant(t_graph *graph, t_room *src, t_room *dst)
{
	assign_whitespace(src);
	write(1, "L", 1);
	ft_putnbr(src->ant);
	write(1, "-", 1);
	ft_putstr(dst->name);
	if (dst == graph->adjlists[graph->end])
		dst->ant = 0;
	else
		dst->ant = src->ant;
	if (src == graph->adjlists[graph->start] && src->ant + 1 <= graph->ants)
		src->ant++;
	else
		src->ant = 0;
}

static t_room	*choose_room(t_graph *graph, t_room *room)
{
	size_t	i;

	i = 0;
	while (i < room->connections)
	{
		if (room->connection[i]->depth > room->depth)
		{
			if (room->connection[i]->ant == 0 && \
			room == graph->adjlists[graph->start] && \
			graph->ants - graph->adjlists[graph->start]->ant + 1 > \
			room->connection[i]->depth - room->depth) //BETA!
				return (room->connection[i]);
			break ;
		}
		if (room->connection[i]->ant == 0)
			return (room->connection[i]);
		i++;
	}
	graph->ants += 0;
	return (NULL);
}

static void	move_ants(t_graph *graph, t_queue *q)
{
	t_room	*cur;
	t_room	*dst;

	enqueue(q, graph->adjlists[graph->start], 0);
	while (!is_empty(q))
	{
		cur = dequeue(q, NULL);
		while (cur->ant)
		{
			dst = choose_room(graph, cur);
			if (dst)
			{
				move_ant(graph, cur, dst);
				if (dst != graph->adjlists[graph->end])
					enqueue(q, dst, 0);
			}
			else
			{
				if (cur->ant)
					enqueue(q, cur, 0);
				break ;
			}
		}
	}
	write(1, "\n", 1);
}

void	solver(t_graph *graph)
{
	t_queue		*q;

	move_ants(graph, q = create_queue());
	free_queue(q);
}

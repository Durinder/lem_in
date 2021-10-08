/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/08 12:59:08 by vhallama         ###   ########.fr       */
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
	static int	prev_ant;

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
/* 	static char	*buffer;
	char		*cur; */

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

static t_room	*choose_room(t_graph *graph, t_room *room)
{
	int	i;

	i = 0;
	while (i < room->links)
	{
		if (room->link[i] == graph->list[graph->start]) // IS THIS NEEDED?
		{
			i++;
			continue ;
		}
		if (room->link[i]->depth > room->depth)
		{
			if (room->link[i]->ant == 0 && \
			room == graph->list[graph->start] && \
			graph->ants - graph->list[graph->start]->ant + 1 > \
			room->link[i]->depth - room->depth) //BETA!
				return (room->link[i]);
			break ;
		}
		if (room->link[i]->ant == 0 || room->link[i] == \
		graph->list[graph->end])
			return (room->link[i]);
		i++;
	}
	return (NULL);
}

static void	move_ants(t_graph *graph, t_queue *q) //MAP25!!!
{
	t_room	*cur;
	t_room	*dst;
	int	WTF = 0;

	enqueue(q, graph->list[graph->start], 0);
	while (!is_empty(q))
	{
		cur = dequeue(q, NULL);
		while (cur->ant)
		{
			dst = choose_room(graph, cur);
			if (dst)
			{
				move_ant(graph, cur, dst);
				if (dst != graph->list[graph->end])
					enqueue(q, dst, 0);
				else
					WTF++;
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
	ft_putnbr(WTF);
}

void	solver(t_graph *graph)
{
	t_queue		*q;

/* 	ft_printf("flow: %d\n", edmonds_karp(graph, graph->list[graph->start], 
	graph->list[graph->end], q = create_queue())); */
//	exit(0);
	move_ants(graph, q = create_queue());
	free_queue(q);
}

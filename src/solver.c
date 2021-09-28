/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/28 16:56:35 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_buf(t_buffer *head)
{
	t_buffer	*cur;

	cur = head;
	while (cur != NULL)
	{
		ft_putendl(cur->move);
		cur = cur->next;
	}
}

static void	print_queue(t_queue *q)
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

static void	pull_ant(t_graph *graph, t_room *dst, t_room *src, t_buffer *buffer)
{
	char	*move;
	char	*tmp;
	size_t	i;

	move = ft_malloc_safe(ft_nbrlen(src->ant) + ft_strlen(dst->name) + 3);
	move[0] = 'L';
	tmp = ft_itoa_ull(src->ant);
	i = ft_strlen(tmp);
	ft_strncpy(move + 1, tmp, i);
	free(tmp);
	move[1 + i] = '-';
	ft_strncpy(move + 2 + i, dst->name, ft_strlen(dst->name) + 1);
//	ft_putendl(move);
	if (dst == graph->adjlists[graph->end])
		dst->ant++;
	else
		dst->ant = src->ant;
	if (src == graph->adjlists[graph->start] && src->ant + 1 <= graph->ants)
		src->ant++;
	else
		src->ant = 0;
/* 	dst->occupants++;
	src->occupants--; */
	push_back_buffer(buffer, move);
}

static void	reset_visited(t_graph *graph)
{
	size_t	i;

	i = 0;
	while (i < graph->total_rooms)
	{
		graph->adjlists[i]->visited = 0;
		i++;
	}
}

static void	loop(t_graph *graph, t_queue *q, t_buffer *buffer)
{
	size_t	i;
	t_room	*cur;
	size_t	done_check;

	reset_visited(graph);
	while (!is_empty(q))
	{
		print_queue(q);
		cur = dequeue(q, NULL);
		i = 0;
		done_check = 0;
		while (i < cur->connections)
		{
			if (cur->depth < cur->connection[i]->depth)
				break ;
			if ((cur->ant == 0 || cur == graph->adjlists[graph->end]) && \
			cur->connection[i] != graph->adjlists[graph->end] && \
			cur->connection[i]->ant)
				pull_ant(graph, cur, cur->connection[i], buffer);
			else if ((cur->connection[i]->done || cur->connection[i] == \
			graph->adjlists[graph->start]) && cur->connection[i]->ant == 0)
				done_check++;
			if (cur->visited == 0 && cur->connection[i] != graph->adjlists[graph->start] && \
				!cur->connection[i]->done)
				enqueue(q, cur->connection[i], 0);
			i++;
		}
		cur->visited++;
		if ((done_check && cur->ant == 0) || \
		(cur == graph->adjlists[graph->end] && cur->ant == graph->ants))
			cur->done = 1;
		if (!cur->done)
			enqueue(q, cur, 0);
	}
	ft_printf("loop over\n");
}

static void	move_ants(t_graph *graph, t_buffer *buffer)
{
	t_queue		*q;

	q = create_queue();
	enqueue(q, graph->adjlists[graph->end], 0);
	loop(graph, q, buffer);
}

void	solver(t_graph *graph)
{
	t_buffer	*buffer;

	buffer = ft_malloc_safe(sizeof(t_buffer));
	buffer->move = NULL;
	buffer->next = NULL;
	move_ants(graph, buffer);
	print_buf(buffer);
}

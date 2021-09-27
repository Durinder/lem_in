/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/27 16:16:06 by vhallama         ###   ########.fr       */
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
		dst->ant = 0;
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

static void	loop(t_graph *graph, t_queue *q, t_buffer *buffer)
{
	size_t	i;
	t_room	*cur;
	size_t	done_check;

	while (!is_empty(q))
	{
		cur = dequeue(q, NULL);
		done_check = 0;
//		cur->in_queue = 0;
		i = 0;
		while (i < cur->connections)
		{
			if ((cur->ant == 0 || cur == graph->adjlists[graph->end]) && \
			cur->connection[i] != graph->adjlists[graph->end] && \
			cur->depth >= cur->connection[i]->depth && cur->connection[i]->ant)
				pull_ant(graph, cur, cur->connection[i], buffer);
			if (cur->connection[i]->done || (cur->connection[i] == \
			graph->adjlists[graph->start] && cur->connection[i]->ant == 0))
				done_check++;
			else if (cur->connection[i] != graph->adjlists[graph->start] && \
			!cur->connection[i]->in_queue)// && (cur->depth >= cur->connection[i]->depth && !cur->connection[i]->in_queue)
			{
				enqueue(q, cur->connection[i], 0);
			//	cur->connection[i]->in_queue = 1;
			}
/* 			else if (cur->ant == 0 || \
			(cur == graph->adjlists[graph->end] && cur->ant == graph->ants))
				cur->done = 1; */
			i++;
		}
		ft_printf("%s has %ld\n", cur->name, cur->ant);
		if (done_check && cur->ant == 0 && cur)// || cur == graph->adjlists[graph->end]))
			cur->done = 1;
 		else /* if (cur == graph->adjlists[graph->end]) */
			enqueue(q, cur, 0);
	}
	ft_printf("moves done!\n");
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

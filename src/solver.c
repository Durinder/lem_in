/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/21 15:15:04 by vhallama         ###   ########.fr       */
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

static void	pull_ant(t_room *dst, t_room *src, t_buffer *buffer)
{
	char	*move;
	char	*tmp;
	size_t	i;

	move = ft_malloc_safe(ft_nbrlen(src->ant) + ft_strlen(dst->name) + 3);
	move[0] = 'L';
	tmp = ft_itoa_ull(src->ant);
	i = ft_strlen(tmp);
	i = ft_strlcat(move, tmp, 1 + i);
	ft_putendl(move);
	ft_putendl(tmp);
	free(tmp);
	move[i] = '-';
	move = ft_strcat(move, dst->name);
	dst->ant = src->ant;
	src->ant = 0;
	dst->occupants++;
	src->occupants--;
	push_back_buffer(buffer, move); // NOT WORKING
}

static void	loop(t_graph *graph, t_queue *q, t_buffer *buffer)
{
	size_t	i;
	t_room	*cur;

	while (!is_empty(q))
	{
		cur = dequeue(q, NULL);
//		ft_putendl(cur->name);
		if (graph->adjlists[graph->start] == cur && cur->occupants == 0)
			cur->done = 1;
		i = 0;
		while (i < cur->connections)
		{
			if (cur->depth >= cur->connection[i]->depth && \
			cur->connection[i]->occupants)
				pull_ant(cur, cur->connection[i], buffer);
			if (!cur->connection[i]->done)
				enqueue(q, cur->connection[i], 0);
			else if ((cur->connection[i]->done && cur->occupants == 0) || \
			(graph->adjlists[graph->end] == cur && cur->occupants == graph->ants))
				cur->done = 1;
			i++;
		}
		if (!cur->done)
			enqueue(q, cur, 0);
	}
	ft_printf("DONE?!\n");
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

	buffer = NULL;
	move_ants(graph, buffer);
	print_buf(buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:24:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/21 14:21:19 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	pull_ant(t_room *dst, t_room *src, t_buffer *buffer)
{
	char	*move;
	char	*tmp;
	size_t	i;

	move = ft_malloc_safe(ft_nbrlen(src->ant) + ft_strlen(dst->name) + 3);
	move[0] = 'L';
	tmp = ft_itoa_ull(src->ant);
	i = ft_strlen(tmp);
	move = ft_strlcat(move, tmp, 1 + i);
	free(tmp);
	move[i + 2] = '-';
	move = ft_strcat(move, dst->name);
	dst->ant = src->ant;
	src->ant = 0;
	dst->occupants++;
	src->occupants--;
	tmp = ft_strdup(buffer);
	free(buffer);
	push_back_buffer(buffer, ft_strjoin(tmp, move));
	free(tmp);
	free(move);
}

static char	*loop(t_graph *graph, t_queue *q, t_buffer *buffer)
{
	size_t	i;
	t_room	*cur;

	while (!is_empty(q))
	{
		cur = dequeue(q, NULL);
		i = 0;
		while (i < cur->connections)
		{
			if (cur->depth >= cur->connection[i]->depth && \
			cur->connection[i]->occupants)
				pull_ant(cur, cur->connection[i], buffer);
		}
	}
}

static void	move_ants(t_graph *graph, char *buffer)
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
	ft_printf("%s\n", buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/08 15:28:43 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/* 
int	edmonds_karp(t_graph *graph, t_room *s, t_room *t, t_queue *q)
{
	t_pred	*pred;
	int		flow;
	int		df;
	t_room	*cur;
	t_room	*tmp;
	int	i;

	pred = ft_malloc_safe(sizeof(t_pred) * graph->total_rooms);
	flow = 0;
	enqueue(q, s, 0);
	while (is_empty(q))
	{
		cur = dequeue(q, NULL);
		i = 0;
		while (i < cur->links)
		{
			if (pred[i].t == NULL && cur->link[i] != s && \
			!cur->edge_flow[i])
			{
				pred[i].t = cur->link[i];
				enqueue(q, cur->link[i], 0);
			}
			if (pred[i].t == t)
			{
				df = INT_MAX;
				tmp = pred[i].t;
				while (tmp != NULL)
				{
					df = 1 - tmp->edge_flow[i];
					tmp = pred[i].s;
				}
				tmp = pred[i].t;
				while (tmp != NULL)
				{
					tmp->edge_flow += df;
				}
				flow += df;
			}
		}
	}
	return (flow);
}
 */

int	bfs(t_graph *g, t_flow **flow_arr, int **parent)
{
	int		*visited;
	t_queue	*q;
	t_room	*cur;
	int		i;

	visited = ft_malloc_safe(sizeof(int) * g->total_rooms);
	q = create_queue();
	enqueue(q, g->list[g->start]);
	visited[(g->list[g->start] - g->list[0]) / sizeof(t_room *)] = 1;
	*parent[(g->list[g->start] - g->list[0]) / sizeof(t_room *)] = -1;
	while (!is_empty(q))
	{
		cur = dequeue(q);
		i = 0;
		while (i++ < cur->links)
		{
			if (!visited[(cur->*link[i] - g->list[0]) / sizeof(t_room *)] && \
			flow_arr[(cur->link[i] - g->list[0]) / sizeof(t_room *)]->from == 0)
			{
				*parent[(cur->link[i] - g->list[0]) / sizeof(t_room *)] = \
				(g->list[0] - cur) / sizeof(t_room *);
				if (cur->link[i] == g->list[g->end])
				{
					free(visited);
					return (1);
				}
				enqueue(q, cur->link[i]);
				visited[(cur->link[i] - g->list[0]) / sizeof(t_room *)] = 1;
			}
		}
	}
	free(visited);
	return (0);
}

int	max_flow(t_graph *graph, t_flags *flags)
{
	t_flow	*flow_arr;
	int		*parent;
	int		flow;

	flow_arr = ft_malloc_safe(sizeof(t_flow) * graph->total_rooms);
	parent = ft_malloc_safe(sizeof(t_room) * graph->total_rooms);
	flow = 0;
	while (bfs(graph, &flow_arr, &parent))
	{
		ft_putendl("loop");
	}
	if (flags)
		ft_printf("redundant.\n");
	free(flow_arr);
	return (flow);
}

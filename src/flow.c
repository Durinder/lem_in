/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/08 09:57:35 by vhallama         ###   ########.fr       */
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
		while (i < cur->connections)
		{
			if (pred[i].t == NULL && cur->connection[i] != s && \
			!cur->edge_flow[i])
			{
				pred[i].t = cur->connection[i];
				enqueue(q, cur->connection[i], 0);
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

/* int	max_flow(t_graph *graph, t_flags *flags)
{

}
 */
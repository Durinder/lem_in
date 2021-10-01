/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:14:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/29 17:01:48 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_queue(t_queue *queue)
{
	t_queue_node	*tmp;

	while (queue->front != NULL)
	{
		tmp = queue->front;
		queue->front = queue->front->next;
		free(tmp);
	}
	free(queue);
}

void	free_init(t_init *init)
{
	t_roomlist	*tmp;

	while (init->head != NULL)
	{
		tmp = init->head;
		init->head = init->head->next;
		free(tmp);
	}
	free(init);
}

void	free_graph(t_graph *graph)
{
	size_t	i;

	i = 0;
	while (i < graph->total_rooms)
	{
		free(graph->adjlists[i]->name);
		free(graph->adjlists[i]->connection);
		free(graph->adjlists[i]);
		i++;
	}
	free(graph->adjlists);
	free(graph);
}

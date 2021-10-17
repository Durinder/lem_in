/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:14:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/17 15:27:11 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delete_queue(t_queue *queue)
{
	t_queue_node	*tmp;

	while (queue->front != NULL)
	{
		tmp = queue->front;
		queue->front = queue->front->next;
		free(tmp);
	}
}

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

void	free_copy(t_room **list, int rooms)
{
	int	i;

	i = 0;
	while (i < rooms)
	{
		free(list[i]->link);
		free(list[i]);
		i++;
	}
	free(list);
}

void	free_graph(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->total_rooms)
	{
		free(graph->list[i]->name);
		free(graph->list[i]->link);
		free(graph->list[i]);
		i++;
	}
	free(graph->list);
	free(graph);
}

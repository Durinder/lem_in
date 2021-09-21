/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:34:26 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/21 13:08:06 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	is_empty(t_queue *queue)
{
	if (queue->front == NULL)
		return (1);
	return (0);
}

static t_queue_node	*create_queue_node(t_room *room, size_t depth)
{
	t_queue_node	*new;

	new = ft_malloc_safe(sizeof(t_queue_node));
	new->room = room;
	new->depth = depth;
	new->next = NULL;
	return (new);
}

t_room	*dequeue(t_queue *queue, size_t *depth)
{
	t_queue_node	*tmp;
	t_room			*ptr;

	if (queue->front == NULL)
		return (NULL);
	ptr = queue->front->room;
	tmp = queue->front;
	queue->front = queue->front->next;
	*depth = tmp->depth;
	free(tmp);
	return (ptr);
}

void	enqueue(t_queue *queue, t_room *room, size_t depth)
{
	t_queue_node	*new;

	new = create_queue_node(room, depth);
	if (queue->front == NULL)
	{
		queue->front = new;
		queue->rear = new;
	}
	else
	{
		queue->rear->next = new;
		queue->rear = new;
	}
}

t_queue	*create_queue(void)
{
	t_queue			*queue;

	queue = ft_malloc_safe(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

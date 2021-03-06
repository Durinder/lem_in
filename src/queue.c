/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:34:26 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/28 16:10:11 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_queue_node	*create_queue_node(t_room *room, t_room *only_dir)
{
	t_queue_node	*new;

	new = ft_malloc_safe(sizeof(t_queue_node));
	new->room = room;
	new->only_dir = only_dir;
	new->next = NULL;
	return (new);
}

t_room	*dequeue(t_queue *queue, t_room **only_dir)
{
	t_queue_node	*tmp;
	t_room			*ptr;

	if (queue->front == NULL)
		return (NULL);
	ptr = queue->front->room;
	tmp = queue->front;
	queue->front = queue->front->next;
	if (only_dir)
		*only_dir = tmp->only_dir;
	free(tmp);
	return (ptr);
}

void	enqueue_front(t_queue *queue, t_room *room, t_room *only_dir)
{
	t_queue_node	*new;
	t_queue_node	*tmp;

	new = create_queue_node(room, only_dir);
	if (queue->front == NULL)
	{
		queue->front = new;
		queue->rear = new;
	}
	else
	{
		tmp = queue->front;
		queue->front = new;
		new->next = tmp;
	}
}

void	enqueue(t_queue *queue, t_room *room, t_room *only_dir)
{
	t_queue_node	*new;

	new = create_queue_node(room, only_dir);
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

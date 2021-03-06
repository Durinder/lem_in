/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/11/09 10:52:42 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	send_flow(t_graph *graph)
{
	t_room	*cur;
	t_room	*prev;

	prev = graph->list[graph->end];
	cur = prev->parent;
	while (cur != graph->list[graph->start])
	{
		if (cur->input == prev && cur->output == cur->parent)
		{
			cur->input = NULL;
			cur->output = NULL;
		}
		else if (cur->input == prev)
			cur->input = cur->parent;
		else if (cur->output == cur->parent)
			cur->output = prev;
		else
		{
			cur->input = cur->parent;
			cur->output = prev;
		}
		prev = cur;
		cur = cur->parent;
	}
}

static int	bfs(t_graph *graph, t_queue *q, t_room *cur, t_room *only)
{
	int		i;

	while (q->front != NULL)
	{
		cur = dequeue(q, &only);
		i = -1;
		while (++i < cur->links)
		{
			if (cur->link[i]->visited == 0 && cur->link[i]->input != cur && \
			cur->output != cur->link[i] && (!only || only == cur->link[i]))
			{
				cur->link[i]->parent = cur;
				if (cur->link[i] == graph->list[graph->end])
					return (1);
				cur->link[i]->visited = 1;
				if (cur->link[i]->output && cur->link[i]->output != cur)
					enqueue_front(q, cur->link[i], cur->link[i]->input);
				else if (cur->link[i]->output)
					enqueue_front(q, cur->link[i], NULL);
				else
					enqueue(q, cur->link[i], NULL);
			}
		}
	}
	return (0);
}

static void	get_routes(t_graph *graph, t_save **save, t_flags *flags)
{
	t_queue	*q;
	int		i;
	int		flow;

	q = create_queue();
	enqueue(q, graph->list[graph->start], NULL);
	graph->list[graph->start]->visited = 1;
	flow = 0;
	while (bfs(graph, q, NULL, NULL))
	{
		flow++;
		send_flow(graph);
		save_best_routing(save, graph, flags);
		delete_queue(q);
		i = 0;
		while (i < graph->total_rooms)
			graph->list[i++]->visited = 0;
		enqueue(q, graph->list[graph->start], NULL);
		graph->list[graph->start]->visited = 1;
	}
	free_queue(q);
	if (flow == 0)
		ft_error_exit("Error: map cannot be solved.");
	fetch_save(graph->list, save, graph->total_rooms);
	free_save(save, graph->total_rooms);
}

static int	end_next_to_start(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->list[graph->start]->links)
	{
		if (graph->list[graph->start]->link[i] == \
		graph->list[graph->end])
		{
			graph->list[graph->start]->output = \
			graph->list[graph->end];
			return (1);
		}
		i++;
	}
	return (0);
}

void	max_flow(t_graph *graph, t_flags *flags)
{
	t_save	**save;

	save = create_save(graph->total_rooms);
	if (end_next_to_start(graph) == 0)
		get_routes(graph, save, flags);
	if (flags)
	{
		if (flags->path)
		{
			set_depth_for_paths(graph);
			print_pathing(graph->list[graph->start]);
		}
	}
}

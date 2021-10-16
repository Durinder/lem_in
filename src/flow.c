/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/16 12:52:04 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	set_depth_for_paths(t_graph *graph)
{
	t_room	*cur;
	int		depth;
	int		i;

	i = 0;
	while (i < graph->list[graph->end]->links)
	{
		if (graph->list[graph->end]->link[i]->output)
		{
			cur = graph->list[graph->end]->link[i];
			depth = 1;
			while (cur != graph->list[graph->start])
			{
				cur->depth = depth++;
				cur = cur->input;
			}
		}
		i++;
	}
}

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

	enqueue(q, graph->list[graph->start], NULL);
	graph->list[graph->start]->visited = 1;
	while (!is_empty(q))
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
					enqueue(q, cur->link[i], cur->link[i]->input);
				else
					enqueue(q, cur->link[i], NULL);
			}
		}
	}
	return (0);
}

static void	get_optimal_routes(t_graph *graph)
{
	t_queue	*q;
	t_room	**cpy;
	int		i;
	int		flow;

	q = create_queue();
	flow = 0;
	cpy = NULL;
	while (bfs(graph, q, NULL, NULL))
	{
		flow++;
		send_flow(graph);
		set_depth_for_paths(graph);
		i = 0;
		while (i < graph->total_rooms)
			graph->list[i++]->visited = 0;
		delete_queue(q);
		copy_optimal_routing_to_cpy(&cpy, graph);
/* 		if (flow == graph->ants)
			break ; */
	}
	free_queue(q);
	if (flow == 0)
		ft_error_exit("Error: map cannot be solved.");
	delete_list(graph->list, graph->total_rooms);
	graph->list = cpy;
}

void	max_flow(t_graph *graph, t_flags *flags)
{
	get_optimal_routes(graph);
	if (flags)
	{
		if (flags->flow)
			print_flow(graph->list[graph->start]);
	}
}

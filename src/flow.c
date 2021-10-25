/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/25 14:27:30 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	send_flow(t_graph *graph)
{
	t_room	*cur;
	t_room	*prev;

	prev = graph->list[graph->end];
	cur = prev->parent;
/* 	if (cur == graph->list[graph->start])
		cur->output = prev; */
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

static void	get_optimal_routes(t_graph *graph, t_save **save)
{
	t_queue	*q;
	int		i;
	int		flow;

	q = create_queue();
	flow = 0;
	while (bfs(graph, q, NULL, NULL))
	{
		flow++;
		send_flow(graph);
		i = 0;
		while (i < graph->total_rooms)
			graph->list[i++]->visited = 0;
		delete_queue(q);
		save_optimal_routing(save, graph);
		if (flow == 1 && graph->ants == 1)
			break ;
	}
	free_queue(q);
	if (flow == 0)
		ft_error_exit("Error: map cannot be solved.");
	fetch_save(graph->list, save, graph->total_rooms);
	free_save(save, graph->total_rooms);
}

void	max_flow(t_graph *graph, t_flags *flags)
{
	t_save	**save;

	save = create_save(graph->total_rooms);
	get_optimal_routes(graph, save);
	if (flags)
	{
		if (flags->flow)
			print_flow(graph->list[graph->start]);
	}
}

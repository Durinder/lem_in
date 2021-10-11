/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 15:51:40 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_flow(t_room *start)
{
	t_room	*cur;
	int		i;

	i = 0;
	while (i < start->links)
	{
		if (start->link[i]->input)
		{
			cur = start->link[i];
			while (cur)
			{
				ft_printf("%s(%d)", cur->name, cur->depth);
				cur = cur->output;
				if (cur)
					ft_printf("->");
			}
			write(1, "\n", 1);
		}
		i++;
	}
}

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

	cur = graph->list[graph->end];
	while (cur != graph->list[graph->start])
	{
		if (cur->input == NULL)
		{
			if (cur != graph->list[graph->end])
				cur->input = cur->parent;
			if (cur->parent != graph->list[graph->start])
				cur->parent->output = cur;
		}
		else if (cur->input)
		{
			if (cur->parent->input == cur)
				cur->parent->input = NULL;
		}
		cur = cur->parent;
	}
}

//parents can be modified, flow is final!
static int	bfs(t_graph *graph, t_queue *q)
{
	t_room	*cur;
	int		i;

	enqueue(q, graph->list[graph->start]);
	graph->list[graph->start]->visited = 1;
	while (!is_empty(q))
	{
		cur = dequeue(q);
		i = 0;
		while (i < cur->links)
		{
			if (cur->link[i]->visited == 0 && cur->link[i]->input != cur && \
			cur->output != cur->link[i])
			{
				cur->link[i]->parent = cur;
				if (cur->link[i] == graph->list[graph->end])
					return (1);
				cur->link[i]->visited = 1;
				enqueue(q, cur->link[i]);
			}
			i++;
		}
	}
	return (0);
}

int	max_flow(t_graph *graph, t_flags *flags)
{
	t_queue	*q;
	t_graph	*cpy;
	int		i;

	q = create_queue();
	while (bfs(graph, q))
	{
		send_flow(graph);
		set_depth_for_paths(graph);
		i = 0;
		while (i < graph->total_rooms)
			graph->list[i++]->visited = 0;
		free_queue(q);
		q = create_queue();
		save_optimal_routing_to_cpy(graph, cpy);
	}
	free_queue(q);
	if (flags)
	{
		if (flags->flow)
			print_flow(graph->list[graph->start]);
	}
	return (i - 1);
}

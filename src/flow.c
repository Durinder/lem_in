/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 14:07:38 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_path(t_room *cur)
{
	while (cur)
	{
		ft_printf("%s", cur->name);
		cur = cur->output;
		if (cur)
			ft_printf("->");
	}
	write(1, "\n", 1);
}

static void	print_flow(t_room *start)
{
	int		i;

	i = 0;
	while (i < start->links)
	{
		if (start->link[i]->input)
			print_path(start->link[i]);
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
	int		i;
	int		flow; // HUOM INT VAI SIZE_T
	
	q = create_queue();
	flow = 0;
	while (bfs(graph, q))
	{
		flow++;
		send_flow(graph);
		i = 0;
		while (i < graph->total_rooms)
			graph->list[i++]->visited = 0;
		free_queue(q);
		q = create_queue();
	}
	free_queue(q);
	if (flags)
	{
		if (flags->flow)
			print_flow(graph->list[graph->start]);
	}
	return (i - 1);
}

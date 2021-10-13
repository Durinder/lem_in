/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/13 14:56:05 by vhallama         ###   ########.fr       */
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
				ft_printf("%s,", cur->name);
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

//parents can be modified, flow is final!
static int	bfs(t_graph *graph, t_queue *q) //VOINEE MENNA FLOW HUONEEN LAPI!
{
	t_room	*cur;
	int		i;
	t_room	*only_dir;

	enqueue(q, graph->list[graph->start], NULL);
	graph->list[graph->start]->visited = 1;
	only_dir = NULL;
	while (!is_empty(q))
	{
		cur = dequeue(q, &only_dir);
		i = 0;
/* 		if (only_dir)
			ft_printf("cur:%s, only_dir%s\n", cur->name, only_dir->name);
		else
			ft_printf("cur:%s, NULL\n", cur->name); */
		while (i < cur->links)
		{
			if (cur->link[i]->visited == 0 && cur->link[i]->input != cur && \
			cur->output != cur->link[i] && \
			(!only_dir || only_dir == cur->link[i]))
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
			i++;
		}
	}
	return (0);
}

int	max_flow(t_graph *graph, t_flags *flags)
{
	t_queue	*q;
//	t_room	**cpy;
	int		i;
	int		flow;

	q = create_queue();
	flow = 0;
//	cpy = NULL;
	while (bfs(graph, q))
	{
		flow++;
		send_flow(graph);
		ft_putendl("hep");
		set_depth_for_paths(graph);
		ft_putendl("hoi");
		i = 0;
		while (i < graph->total_rooms)
			graph->list[i++]->visited = 0;
		free_queue(q);
		q = create_queue();
	//	save_optimal_routing_to_cpy(graph, cpy);
		if (flow == graph->ants)
			break ;
	}
/* 	if (cpy)
	{
		free(graph->list);
		graph->list = cpy;
	} */
	free_queue(q);
	if (flags)
	{
		if (flags->flow)
			print_flow(graph->list[graph->start]);
	}
	return (i - 1);
}

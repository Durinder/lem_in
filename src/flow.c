/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:57:10 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/22 10:42:21 by vhallama         ###   ########.fr       */
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
// EKALLA KERRALLA LOOP JA EI SAA REROUTTAA
// TOKALLA KERRALLA REROUT KAYTTOON!
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
/* 
static void	test(t_room *start)
{
	int	i = 0;

	while (i < start->links)
	{
		if (start->link[i]->input == NULL)
			break ;
		ft_putstr(start->link[i]->name);
		ft_putchar(',');
		i++;
	}
	ft_putchar('\n');
}*/

static void	print(t_room **cpy, int rooms)
{
	int	i = 0;
	int	j = 0;

	while (i < rooms)
	{
		ft_printf("%s:%p, in:%p, out:%p, %d\n", cpy[i]->name, cpy[i], cpy[i]->input, cpy[i]->output, cpy[i]->depth);
		j = 0;
		while (j < cpy[i]->links)
		{
			ft_printf("%s, ", cpy[i]->link[j]->name);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
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
		set_depth_for_paths(graph);
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
	print(graph->list, graph->total_rooms);
}

void	max_flow(t_graph *graph, t_flags *flags)
{
	t_save	**save;
	int		i;

	save = (t_save **)ft_malloc_safe(sizeof(t_save *) * graph->total_rooms);
	i = 0;
	while (i < graph->total_rooms)
	{
		save[i] = (t_save *)ft_malloc_safe(sizeof(t_save));
		i++;
	}
	get_optimal_routes(graph, save);
	if (flags)
	{
		if (flags->flow)
			print_flow(graph->list[graph->start]);
	}
}

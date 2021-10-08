/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/08 08:44:26 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* static void	print2(t_graph *graph)
{
  	size_t	i = 0;
	size_t	j;
	ft_printf("\n");
	while (i < graph->total_rooms)
	{
		j = 0;
		while (j < graph->adjlists[i]->child_amount)
		{
			ft_printf("%s(%ld)-child>%s\n", graph->adjlists[i]->name, j, graph->adjlists[i]->child[j]->name);
			j++;
		}
		j = 0;
		while (j < graph->adjlists[i]->parent_amount)
		{
			ft_printf("%s(%ld)-parent>%s\n", graph->adjlists[i]->name, j, graph->adjlists[i]->parent[j]->name);
			j++;
		}		
		i++;
	}
} */
/* 
static void	print(t_graph *graph)
{
  	size_t	i = 0;
	size_t	j;
	ft_printf("\n");
	while (i < graph->total_rooms)
	{
		j = 0;
		while (j < graph->adjlists[i]->connections)
		{
			ft_printf("%s(%ld)->%s\n", graph->adjlists[i]->name, j, graph->adjlists[i]->connection[j]->name);
			j++;
		}
		i++;
	}
}
 */
static t_init	*get_t_init(void)
{
	t_init	*init;

	init = ft_malloc_safe(sizeof(t_init));
	init->head = NULL;
	init->line = NULL;
	init->ants = 0;
	init->ret = 0;
	init->start_check = 0;
	init->end_check = 0;
	init->start = 0;
	init->end = 0;
	init->total_rooms = 0;
	init->comment_check = 0;
	return (init);
}

t_graph	*initialize(t_flags *flags)
{
	t_graph		*graph;
	t_init		*init;

	init = get_t_init();
	assign_ants(init);
	assign_rooms(init, 0);
	validate_start_and_end(init);
	graph = create_graph(init);
	assign_links(graph, init);
	free_init(init);
//	print(graph);
//	ft_putchar('\n');
	assign_depth(graph, flags);
	return (graph);
}

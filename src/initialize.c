/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 15:07:56 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* 
static void	print(t_graph *graph)
{
	int	i;
	int	j;

	i = 0;
	ft_putendl("graph:");
	while (i < graph->total_rooms)
	{
		j = 0;
		while (j < graph->list[i]->links)
		{
			ft_printf("%s(%ld)->%s\n", graph->list[i]->name, \
			j, graph->list[i]->link[j]->name);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
} */

t_graph	*initialize(t_flags *flags)
{
	t_graph		*graph;
	t_init		*init;

	init = ft_malloc_safe(sizeof(t_init));
	assign_ants(init);
	assign_rooms(init, 0);
	validate_start_and_end(init);
	graph = create_graph(init);
	assign_links(graph, init);
	free_init(init);
	write(1, "\n", 1);
//	ft_putchar('\n');
//	assign_depth(graph, flags);
	if (flags)
		ft_putstr(""); // POISTA
	return (graph);
}

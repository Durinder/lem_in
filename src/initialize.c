/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 11:06:30 by vhallama         ###   ########.fr       */
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
}
 */
/* static t_init	*get_t_init(void)
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
 */
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

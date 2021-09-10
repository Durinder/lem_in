/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/10 15:32:57 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_init	*get_t_init(void)
{
	t_init	*init;

	init = ft_malloc_safe(sizeof(t_init));
	init->head = ft_malloc_safe(sizeof(t_roomlist));
	init->line = NULL;
	init->ants = 0;
	init->ret = 0;
	init->start_check = 0;
	init->end_check = 0;
	init->start = 0;
	init->end = 0;
	init->total_rooms = 0;
	return (init);
}

t_graph	*initialize(void)
{
	t_graph		*graph;
	t_init		*init;

	init = get_t_init();
	assign_ants(init);
	assign_rooms(init, 0);
	if (init->start_check != 1 || init->end_check != 1 || \
			init->start == init->end || init->start == init->total_rooms || \
			init->end == init->total_rooms)
		ft_error_exit("Error: invalid start and/or end room(s).");
	graph = create_graph(init);
	assign_links(graph, init, 0, 0);
	free_init(init);
	free_graph(graph);
	ft_putchar('\n');
	exit(0);
	return (graph);
}

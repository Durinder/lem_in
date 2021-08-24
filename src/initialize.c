/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/24 17:12:37 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	initialize(t_graph *graph)
{
	t_init	init;

	init.line = NULL;
	init.start_check = 0;
	init.end_check = 0;
	assign_ants(graph, &init);
	assign_rooms(graph, &init, 0);
	if (init.start_check != 1 || init.end_check != 1 || \
			graph->start == graph->end || !graph->adjlists[graph->start] || \
			!graph->adjlists[graph->end])
		ft_error_exit("Error: invalid start and/or end room(s).");
	while (init.ret > 0)
	{
		assign_links(graph, &init, 0, 0);
		ft_putendl(init.line);
		free(init.line);
		init.ret = get_next_line(0, &init.line);
		if (init.ret == -1)
			ft_error_exit("Error: reading.");
	}
	ft_putchar('\n');
}

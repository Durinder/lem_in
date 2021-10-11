/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:45:07 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 16:02:31 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	calculate_printing_line_amount(t_graph *graph)
{
	int	ret;
	int paths;
	int	i;

	ret = 0;
	paths = 0;
	i = 0;
	while (graph->list->link[i])
}

void	save_optimal_routing_to_cpy(graph, cpy)
{
	static int	record;
	int			lines;

	lines = calculate_printing_line_amount(graph);
	if (lines < record || record == 0)
	{
		record = lines;
		if (cpy)
			free_graph(cpy);
		cpy = copy_graph(graph);
	}
}

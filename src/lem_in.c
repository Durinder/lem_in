/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/17 15:38:29 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h> // HUOM
#include <time.h> // HUOM

int	main(int argc, char **argv)
{
	clock_t	start, init, end;
	double	init_time, execution_time;
	t_graph	*graph;
	t_flags	*flags;

	start = clock();
	if (argc > 1)
		flags = assign_flags(argc, argv);
	else
		flags = NULL;
	graph = initialize();
	init = clock();
//	ft_printf("exec time:%d\n", execution_time);
//	solver(graph);
	if (graph->total_rooms > 2) // HUOM!
		max_flow(graph, flags);
	move_ants(graph);
	free_graph(graph);
	free(flags);
	end = clock();
	init_time = ((double)(init - start))/CLOCKS_PER_SEC;
	execution_time = ((double)(end - init))/CLOCKS_PER_SEC;
	ft_printf("init time:%f\nsolver time:%f\n", init_time, execution_time);
	return (0);
}

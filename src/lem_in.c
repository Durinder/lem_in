/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/02 15:33:14 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>
#include <time.h>

int	main(int argc, char **argv)
{
	clock_t	start, init, end;
	double	init_time, execution_time;
	start = clock();
	t_graph	*graph;

	if (argc > 1)
	{
		ft_printf("Usage: './lem < %s'", argv[1]);
		if (argc > 2) // FLAGS?
			ft_printf(" Only 1 map at a time.");
		ft_error_exit("");
	}
	graph = initialize();
	init = clock();
//	ft_printf("exec time:%d\n", execution_time);
	solver(graph);
	end = clock();
	init_time = ((double)(init - start))/CLOCKS_PER_SEC;
	execution_time = ((double)(end - init))/CLOCKS_PER_SEC;
	ft_printf("init time:%f\nsolver time:%f\n", init_time, execution_time);
	free_graph(graph);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/21 13:24:16 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int argc, char **argv)
{
	t_graph	*graph;

	if (argc > 1)
	{
		ft_printf("Usage: './lem < %s'", argv[1]);
		if (argc > 2)
			ft_printf(" Only 1 map at a time.");
		ft_error_exit("");
	}
	graph = initialize();
	solver(graph);
	free_graph(graph);
	return (0);
}

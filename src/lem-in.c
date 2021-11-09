/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/11/09 11:03:26 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int argc, char **argv)
{
	t_graph	*graph;
	t_flags	*flags;

	if (argc > 1)
		flags = assign_flags(argc, argv);
	else
		flags = NULL;
	graph = initialize();
	max_flow(graph, flags);
	move_ants(graph, flags);
	free_graph(graph);
	free(flags);
	return (0);
}

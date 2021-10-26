/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/26 15:56:42 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_graph	*initialize(void)
{
	t_graph		*graph;
	t_init		*init;

	init = ft_malloc_safe(sizeof(t_init));
	assign_ants(init);
	assign_rooms(init, 0);
	validate_start_and_end(init);
	graph = create_graph(init);
	assign_links(graph, init, NULL, NULL);
	free_init(init);
	return (graph);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/18 17:33:31 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_graph	*graph;

	graph = create_graph(HASH_SIZE);
	initialize(graph);
	free_graph(graph);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/13 15:59:32 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
/* 	t_graph	*graph;

	graph = (t_graph *)malloc(sizeof(t_graph));
	if (graph == NULL)
		ft_error_exit("Error: malloc"); */
	reader(graph);
	return (0);
}

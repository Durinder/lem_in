/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:14:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/24 15:14:29 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_graph(t_graph *graph)
{
	size_t	i;
	t_room	*tmp;

	i = 0;
	while (i < graph->total_rooms)
	{
		while (graph->adjlists[i] != NULL)
		{
			tmp = graph->adjlists[i];
			graph->adjlists[i] = graph->adjlists[i]->next;
			free(tmp->name);
			free(tmp);
		}
		free(graph->adjlists[i]);
		i++;
	}
	free(graph->adjlists);
	free(graph);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:14:00 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/10 15:35:31 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_init(t_init *init)
{
	t_roomlist	*cur;

	while (init->head != NULL)
	{
		cur = init->head;
		init->head = init->head->next;
//		free(cur->name);
		free(cur);
	}
	free(init);
}

void	free_graph(t_graph *graph)
{
	size_t	i;

	i = 0;
	while (i < graph->total_rooms)
	{
		free(graph->adjlists[i]->name);
		free(graph->adjlists[i]->child);
		free(graph->adjlists[i]->parent);
		free(graph->adjlists[i]);
		i++;
	}
	free(graph->adjlists);
	free(graph);
}

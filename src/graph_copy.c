/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:18:54 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/20 09:57:48 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	copy_list(t_room **cpy, t_graph *graph)
{
	int	i;
	int	j;

	i = 0;
	while (i < graph->total_rooms)
	{
		ft_memcpy(cpy[i], graph->list[i], sizeof(t_room));
/* 		cpy[i]->depth = graph->list[i]->depth;
		cpy[i]->input = graph->list[i]->input;
		cpy[i]->output = graph->list[i]->output; */
		if (graph->list[i] == graph->list[graph->start])
		{
			j = 0;
			while (j < graph->list[i]->links)
			{
				ft_memcpy(cpy[i]->link[j], graph->list[i]->link[j], sizeof(t_room *));
				j++;
			}
		}
		i++;
	}
}

t_room	**duplicate_list(t_graph *graph)
{
	t_room	**dup;
	int		i;
	int		j;

	dup = ft_malloc_safe(sizeof(t_room *) * graph->total_rooms);
	i = 0;
	while (i < graph->total_rooms)
	{
		dup[i] = ft_malloc_safe(sizeof(t_room));
		ft_memcpy(dup[i], graph->list[i], sizeof(t_room));
		if (graph->list[i] == graph->list[graph->start])
		{
			dup[i]->link = ft_malloc_safe(sizeof(t_room *) * \
			graph->list[i]->links);
			j = 0;
			while (j < graph->list[i]->links)
			{
				dup[i]->link[j] = ft_malloc_safe(sizeof(t_room *));
				ft_memcpy(dup[i]->link[j], graph->list[i]->link[j], \
				sizeof(t_room *));
				j++;
			}
		}
		i++;
	}
	return (dup);
}

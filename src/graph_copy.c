/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:18:54 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/20 14:50:57 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	copy_list(t_room **cpy, t_room **src, int rooms, int start)
//int free_links
{
	int		i;
	int		j;

	i = 0;
	while (i < rooms)
	{
		cpy[i]->depth = src[i]->depth;
		cpy[i]->input = src[i]->input;
		cpy[i]->output = src[i]->output;
		if (i == start)
		{
			j = 0;
			while (j < src[i]->links)
			{
				cpy[i]->link[j] = src[i]->link[j];
				j++;
			}
		}
		i++;
	}
}
/* 
t_room	**duplicate_list(t_room **src, int rooms)
{
	t_room	**dup;
	int		i;
	int		j;

	dup = ft_malloc_safe(sizeof(t_room *) * rooms);
	i = 0;
	while (i < rooms)
	{
		dup[i] = ft_malloc_safe(sizeof(t_room));
		dup[i]->ant = src[i]->ant;
		dup[i]->depth = src[i]->depth;
		dup[i]->input = src[i]->input;
		dup[i]->links = src[i]->links;
		dup[i]->link = ft_malloc_safe(sizeof(t_room *) * src[i]->links);
		j = -1;
		while (++j < src[i]->links)
			dup[i]->link[j] = src[i]->link[j];
		dup[i]->name = src[i]->name;
		dup[i]->output = src[i]->output;
		dup[i]->parent = src[i]->parent;
		dup[i]->visited = src[i]->visited;
		i++;
	}
	return (dup);
} */

t_room	**duplicate_list(t_graph *graph)
{
	t_room	**dup;
	int		i;
//	int		j;

	dup = ft_malloc_safe(sizeof(t_room *) * graph->total_rooms);
	i = 0;
	while (i < graph->total_rooms)
	{
		dup[i] = ft_malloc_safe(sizeof(t_room));
		ft_memcpy(dup[i], graph->list[i], sizeof(t_room));
		if (graph->list[i] == graph->list[graph->start])
		{
			dup[i]->link = ft_malloc_safe(sizeof(t_room *) * graph->list[i]->links);
			ft_memcpy(dup[i]->link, graph->list[i]->link, sizeof(t_room *) * graph->list[i]->links);
//			j = 0;
//			while (j < graph->list[i]->links)
//			{
		//		dup[i]->link[j] = ft_malloc_safe(sizeof(t_room *));
//				ft_memcpy(dup[i]->link[j], graph->list[i]->link[j], sizeof(t_room *));
//				j++;
//			}
		}
/* 		dup[i]->input = ft_malloc_safe(sizeof(t_room *));
		dup[i]->input = ft_memcpy(dup[i]->input, src[i]->input, \
		sizeof(t_room *));
		ft_putendl("hei");
		dup[i]->output = ft_malloc_safe(sizeof(t_room *));
		dup[i]->output = ft_memcpy(dup[i]->output, src[i]->output, \
		sizeof(t_room *));
		dup[i]->link = ft_malloc_safe(sizeof(t_room *) * src[i]->links);
		j = 0;
		while (j < src[i]->links)
		{
			dup[i]->link[j] = ft_memcpy(dup[i]->link[j], src[i]->link[j], \
			sizeof(t_room *));
			j++;
		} */
		i++;
	}
	return (dup);
}

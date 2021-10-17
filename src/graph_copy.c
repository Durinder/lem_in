/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:18:54 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/17 15:23:48 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	copy_list(t_room **cpy, t_room **src, int rooms)
{
	int		i;
	int		j;

	i = 0;
	while (i < rooms)
	{
		cpy[i] = ft_malloc_safe(sizeof(t_room));
		cpy[i]->ant = src[i]->ant;
		cpy[i]->depth = src[i]->depth;
		cpy[i]->input = src[i]->input;
		cpy[i]->link = ft_malloc_safe(sizeof(t_room *) * src[i]->links);
		cpy[i]->links = src[i]->links;
		j = 0;
		while (j < src[i]->links)
		{
			cpy[i]->link[j] = src[i]->link[j];
			j++;
		}
		cpy[i]->name = src[i]->name;
		cpy[i]->output = src[i]->output;
		cpy[i]->parent = src[i]->parent;
		cpy[i]->visited = src[i]->visited;
		i++;
	}
}

t_room	**duplicate_list(t_room **src, int rooms)
{
	t_room	**cpy;
	int		i;
	int		j;

	cpy = ft_malloc_safe(sizeof(t_room *) * rooms);
	i = 0;
	while (i < rooms)
	{
		cpy[i] = ft_malloc_safe(sizeof(t_room));
		cpy[i]->ant = src[i]->ant;
		cpy[i]->depth = src[i]->depth;
		cpy[i]->input = src[i]->input;
		cpy[i]->link = ft_malloc_safe(sizeof(t_room *) * src[i]->links);
		cpy[i]->links = src[i]->links;
		j = -1;
		while (++j < src[i]->links)
			cpy[i]->link[j] = src[i]->link[j];
		cpy[i]->name = src[i]->name;
		cpy[i]->output = src[i]->output;
		cpy[i]->parent = src[i]->parent;
		cpy[i]->visited = src[i]->visited;
		i++;
	}
	return (cpy);
}

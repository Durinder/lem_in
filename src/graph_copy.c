/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:24:54 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 17:08:14 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	overwrite_list(t_room **cpy, t_room **src, int rooms)
{
	int		i;

	i = 0;
	while (i < rooms)
	{
		ft_memcpy(cpy[i], src[i], sizeof(t_room));
		i++;
	}
}

t_room	**copy_list(t_room **src, int rooms)
{
	t_room	**cpy;
	int		i;

	cpy = ft_malloc_safe(sizeof(t_room *) * rooms);
	i = 0;
	while (i < rooms)
	{
		cpy[i] = ft_malloc_safe(sizeof(t_room));
		ft_memcpy(cpy[i], src[i], sizeof(t_room));
		i++;
	}
	return (cpy);
}
/* 
t_graph	*copy_graph(t_graph *src)
{
	t_graph	*cpy;
	int		i;

	cpy = ft_malloc_safe(sizeof(t_graph));
	cpy = ft_memcpy(cpy, src, sizeof(t_graph));
	cpy->list = ft_malloc_safe(sizeof(t_room *) * src->total_rooms);
	i = 0;
	while (i < src->total_rooms)
	{
		cpy->list[i] = ft_memcpy(cpy->list[i], src->list[i], sizeof(t_room));
		i++;
	}
	return (cpy);
}
 */
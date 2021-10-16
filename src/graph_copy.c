/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:18:54 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/16 13:49:12 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	copy_list(t_room **cpy, t_room **src, int rooms)
{
	int		i;

	i = 0;
	while (i < rooms)
	{
		ft_memcpy(cpy[i], src[i], sizeof(t_room));
		i++;
	}
}

t_room	**duplicate_list(t_room **src, int rooms)
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

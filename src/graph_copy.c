/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:24:54 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/11 15:35:37 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

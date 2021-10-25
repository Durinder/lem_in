/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:18:54 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/25 12:46:09 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	fetch_save(t_room **dst, t_save **save, int rooms)
{
	int	i;

	i = 0;
	while (i < rooms)
	{
		dst[i]->input = &(*save[i]->input);
		dst[i]->output = &(*save[i]->output);
		dst[i]->load = save[i]->load;
		i++;
	}
}

void	save_state(t_save **save, t_room **src, int rooms)
{
	int	i;

	i = 0;
	while (i < rooms)
	{
		save[i]->input = &(*src[i]->input);
		save[i]->output = &(*src[i]->output);
		save[i]->load = src[i]->load;
		i++;
	}
}

t_save	**create_save(int rooms)
{
	t_save	**save;
	int		i;

	save = (t_save **)ft_malloc_safe(sizeof(t_save *) * rooms);
	i = 0;
	while (i < rooms)
	{
		save[i] = (t_save *)ft_malloc_safe(sizeof(t_save));
		i++;
	}
	return (save);
}

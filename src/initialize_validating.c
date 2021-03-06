/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_validating.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:00:57 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/26 15:56:19 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_if_link_exists(t_room *room1, t_room *room2)
{
	int	i;

	i = 0;
	while (i < room1->links)
	{
		if (room1->link[i] == room2)
			ft_error_exit("Error: same link twice.");
		i++;
	}
}

//which == 1 is room1, 2 is room2
t_room	*find_and_validate_room(t_graph *graph, t_init *init, int dash,
short which)
{
	int		i;
	char	*substr;

	i = 0;
	if (which == 1)
	{
		substr = ft_strsub(init->line, 0, dash);
		while (!ft_strequ(substr, graph->list[i++]->name))
		{
			if (i == graph->total_rooms)
				ft_error_exit("Error: room1 of link not found.");
			free(substr);
			substr = ft_strsub(init->line, 0, dash);
		}
		free(substr);
	}
	else
	{
		while (!(ft_strequ(init->line + dash + 1, graph->list[i++]->name)))
			if (i == graph->total_rooms)
				ft_error_exit("Error: room2 of link not found.");
	}
	return (graph->list[--i]);
}

void	validate_start_and_end(t_init *init)
{
	if (init->start_check != 1 || init->end_check != 1 || \
			init->start == init->end || init->start == init->total_rooms || \
			init->end == init->total_rooms)
		ft_error_exit("Error: invalid start and/or end room(s).");
}

static void	check_for_duplicate_coordinates(t_roomlist *head, int *xy)
{
	t_roomlist	*cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->xy[0] == xy[0])
		{
			if (cur->xy[1] == xy[1])
				ft_error_exit("Error: duplicate room coordinates.");
		}
		cur = cur->next;
	}
}

int	*validate_coordinates(t_init *init, int i)
{
	int	*ret;

	ret = ft_malloc_safe(sizeof(int) * 2);
	if (ft_isalnum(init->line[0]) == 0 || init->line[i++] != ' ')
		ft_error_exit("Error: invalid input line or missing coordinates.");
	if (ft_isdigit(init->line[i]) == 0)
		ft_error_exit("Error: invalid room coordinates.");
	ret[0] = ft_atoi(init->line + i);
	while (ft_isdigit(init->line[i]))
		i++;
	if (init->line[i++] != ' ')
		ft_error_exit("Error: invalid room coordinates.");
	if (ft_isdigit(init->line[i]) == 0)
		ft_error_exit("Error: invalid room coordinates.");
	ret[1] = ft_atoi(init->line + i);
	while (ft_isdigit(init->line[i]))
		i++;
	if (init->line[i] != '\0')
		ft_error_exit("Error: invalid room coordinates.");
	check_for_duplicate_coordinates(init->head, ret);
	ft_putendl(init->line);
	return (ret);
}

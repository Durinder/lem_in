/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:16:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/08 14:16:33 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <limits.h>

/* void	assign_links(t_graph *graph, t_init *init, size_t i, size_t j)
{
	t_room	*cur;

	if (init->line[0] == '#')
	{
		if (ft_strequ(init->line, "##start") || ft_strequ(init->line, "##end"))
			ft_error_exit("Error: invalid ##start or ##end input.");
		return ;
	}
	j = 0;
	while (ft_isalnum(init->line[j]))
		j++;
	if (init->line[j] != '-')
		ft_error_exit("Error: invalid input.");
	i = 0;
	while (!(ft_strnequ(init->line, graph->adjlists[i++]->name, j)))
		if (graph->adjlists[i] == NULL)
			ft_error_exit("Error: room1 of link not found.");
	cur = graph->adjlists[--i];
	i = 0;
	while (!(ft_strequ(init->line + j + 1, graph->adjlists[i++]->name)))
		if (graph->adjlists[i] == NULL)
			ft_error_exit("Error: room2 of link not found.");
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = create_node(ft_strdup(init->line + j + 1));
}
 */
static void	validate_coordinates(const char *line, size_t i) // EI HUOMIOI PAALLEKKAISIA HUONEITA!
{
	if (ft_isalnum(line[0]) == 0)
		ft_error_exit("Error: empty line.");
	if (line[i] != ' ')
		ft_error_exit("Error: invalid room coordinates.");
	i++;
	if (ft_isdigit(line[i]) == 0)
		ft_error_exit("Error: invalid room coordinates.");
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		ft_error_exit("Error: invalid room coordinates.");
	i++;
	if (ft_isdigit(line[i]) == 0)
		ft_error_exit("Error: invalid room coordinates.");
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != '\0')
		ft_error_exit("Error: invalid room coordinates.");
	ft_putendl(line);
}

static void	assign_comments(t_init *init)
{
	if (ft_strequ(init->line, "##start"))
	{
		init->start = init->total_rooms;
		init->start_check++;
	}
	else if (ft_strequ(init->line, "##end"))
	{
		init->end = init->total_rooms;
		init->end_check++;
	}
	ft_putendl(init->line);
}

void	assign_rooms(t_init *init, t_roomlist *head, size_t i)
{
	init->ret = get_next_line(0, &init->line);
	if (init->ret < 1)
		ft_error_exit("Error: reading or invalid input.");
	while (init->ret > 0)
	{
		if (init->line[0] == '#')
			assign_comments(init);
		else
		{
			i = 0;
			while (ft_isalnum(init->line[i]))
				i++;
			if (init->line[i] == '-')
				break ;
			validate_coordinates(init->line, i);
			push_back(head, ft_strsub(init->line, 0, i));
			init->total_rooms++;
		}
		free(init->line);
		init->ret = get_next_line(0, &init->line);
		if (init->ret == -1)
			ft_error_exit("Error: reading.");
	}
}

void	assign_ants(t_init *init)
{
	size_t	i;

	init->ret = get_next_line(0, &init->line);
	if (init->ret == -1)
		ft_error_exit("Error: reading.");
	else if (init->ret == 0)
		exit (0);
	i = 0;
	if (init->line[i] == '+')
		i++;
	while (init->line[i] != '\0')
	{
		if (ft_isdigit(init->line[i]) == 0)
			ft_error_exit("Error: number_of_ants invalid.");
		i++;
	}
	init->ants = (size_t)ft_atoi_l(init->line);
	if (init->ants < 1)
		ft_error_exit("Error: no ants.");
	else if (init->ants > INT_MAX)
		ft_error_exit("Error: over INT_MAX ants.");
	ft_putendl(init->line);
	free(init->line);
}

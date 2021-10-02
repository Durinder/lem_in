/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_assigns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:16:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/02 11:38:02 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

//which == 0 is redirection from assign_rooms() and which == 1 is redirection
//from assign_links()
static void	assign_comments(t_init *init, short which)
{
	if (init->comment_check == 1)
		ft_error_exit("Error: comment after ##start or ##end.");
	if (ft_strequ(init->line, "##start"))
	{
		if (which == 1)
			ft_error_exit("Error: invalid start room.");
		init->start = init->total_rooms;
		init->start_check++;
		init->comment_check = 1;
	}
	else if (ft_strequ(init->line, "##end"))
	{
		if (which == 1)
			ft_error_exit("Error: invalid end room.");
		init->end = init->total_rooms;
		init->end_check++;
		init->comment_check = 1;
	}
	ft_putendl(init->line);
}

void	assign_links(t_graph *graph, t_init *init)
{
	t_room	*room1;
	t_room	*room2;
	size_t	i;

	while (init->ret > 0)
	{
		if (init->line[0] == '#')
			assign_comments(init, 1);
		else
		{
			i = 0;
			while (ft_isalnum(init->line[i]))
				i++;
			if (init->line[i] != '-')
				ft_error_exit("Error: invalid input.");
			room1 = find_and_validate_room(graph, init, i, 1);
			room2 = find_and_validate_room(graph, init, i, 2);
			add_edge(room1, room2);
			ft_putendl(init->line);
		}
		free(init->line);
		init->ret = get_next_line(0, &init->line);
		if (init->ret == -1)
			ft_error_exit("Error: reading.");
	}
}

void	assign_rooms(t_init *init, size_t i)
{
	int	*xy;

	while (1)
	{
		init->ret = get_next_line(0, &init->line);
		if (init->ret < 1)
			ft_error_exit("Error: invalid input or reading.");
		if (init->line[0] == '#')
			assign_comments(init, 0);
		else
		{
			if (init->line[0] == 'L')
				ft_error_exit("Error: room name starts with L.");
			init->comment_check = 0;
			i = 0;
			while (ft_isalnum(init->line[i]))
				i++;
			if (init->line[i] == '-')
				break ;
			xy = validate_coordinates(init, i);
			push_back_roomlist(init->head, ft_strsub(init->line, 0, i), xy);
			init->total_rooms++;
		}
		free(init->line);
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
	else if (init->ants > UINT_MAX)
		ft_error_exit("Error: over UINT_MAX ants.");
	ft_putendl(init->line);
}

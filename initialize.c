/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/18 17:49:52 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	assign_links(t_graph *graph, t_init *init, int i, int j)
{
	t_room	*cur;

	if (init->line[0] != '#')
	{
		j = 0;
		while (ft_isprint(init->line[j]))
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
}

static void	validate_coordinates(const char *line, int i)
{
	if (ft_isprint(line[0]) == 0)
		ft_error_exit("Error: empty or non-printable line.");
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
}

static void	assign_rooms(t_graph *graph, t_init *init, int i)
{
	init->ret = get_next_line(0, &init->line);
	if (init->ret < 1)
		ft_error_exit("Error: reading or invalid input.");
	while (init->ret > 0)
	{
		if (ft_strequ(init->line, "##start"))
			graph->start = graph->total_rooms + 1;
		else if (ft_strequ(init->line, "##end"))
			graph->end = graph->total_rooms + 1;
		else
		{
			i = 0;
			while (ft_isprint(init->line[i]))
				i++;
			if (init->line[i] == '-')
				break ;
			validate_coordinates(init->line, i);
			graph->adjlists[graph->total_rooms++] = \
				create_node(ft_strsub(init->line, 0, i));
		}
		free(init->line);
		init->ret = get_next_line(0, &init->line);
		if (init->ret == -1)
			ft_error_exit("Error: reading.");
	}
}

static void	assign_ants(t_graph *graph, t_init *init)
{
	int	i;

	init->ret = get_next_line(0, &init->line);
	if (init->ret == -1)
		ft_error_exit("Error: reading.");
	else if (init->ret == 0)
		exit (0);
	while (init->line[i] != '\0')
	{
		if (ft_isdigit(init->line[i] == 0))
			ft_error_exit("Error: number_of_ants invalid.");
		i++;
	}
	graph->ants = ft_atoi(init->line);
	if (graph->ants < 1)
		ft_error_exit("Error: no ants.");
	free(init->line);
}

void	initialize(t_graph *graph)
{
	t_init	init;

	init.line = NULL;
	init.room_type = 0;
	assign_ants(graph, &init);
	assign_rooms(graph, &init, 0);
	while (init.ret > 0)
	{
		assign_links(graph, &init, 0, 0);
		free(init.line);
		init.ret = get_next_line(0, &init.line);
		if (init.ret == -1)
			ft_error_exit("Error: reading.");
	}		
}

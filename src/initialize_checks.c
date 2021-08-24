/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:16:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/24 17:14:57 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	assign_links(t_graph *graph, t_init *init, size_t i, size_t j)
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

static void	validate_coordinates(const char *line, size_t i)
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

static void	assign_comments(t_graph *graph, t_init *init)
{
	if (ft_strequ(init->line, "##start"))
	{
		graph->start = graph->total_rooms;
		init->start_check++;
	}
	else if (ft_strequ(init->line, "##end"))
	{
		graph->end = graph->total_rooms;
		init->end_check++;
	}
	ft_putendl(init->line);
}

void	assign_rooms(t_graph *graph, t_init *init, size_t i)
{
	init->ret = get_next_line(0, &init->line);
	if (init->ret < 1)
		ft_error_exit("Error: reading or invalid input.");
	while (init->ret > 0)
	{
		if (init->line[0] == '#')
			assign_comments(graph, init);
		else
		{
			i = 0;
			while (ft_isalnum(init->line[i]))
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
		if (graph->total_rooms % GRAPH_START_SIZE == 0)
			realloc_graph(graph);
	}
}

void	assign_ants(t_graph *graph, t_init *init)
{
	size_t	i;

	init->ret = get_next_line(0, &init->line);
	if (init->ret == -1)
		ft_error_exit("Error: reading.");
	else if (init->ret == 0)
		exit (0);
	i = 0;
	while (init->line[i] != '\0')
	{
		if (init->line[i] == '+')
			i++;
		if (ft_isdigit(init->line[i]) == 0)
			ft_error_exit("Error: number_of_ants invalid.");
		i++;
	}
	graph->ants = ft_atoi(init->line);
	if (graph->ants < 1)
		ft_error_exit("Error: no ants.");
	ft_putendl(init->line);
	free(init->line);
}

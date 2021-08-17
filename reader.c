/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/17 10:19:08 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	line_type_switch(t_graph *graph, t_reader *reader)
{
	if (reader->line_type == 0)
		ft_error_exit("Error");
	else if (reader->line_type == 1)
	{
		if (ft_strcmp("##start", reader->line) == 0)
			reader->room_type = 1;
		else if (ft_strcmp("##end", reader->line) == 0)
			reader->room_type = 2;
	}
	else if (reader->line_type == 2)
		graph->total_rooms++;
		insert(graph->adjlists)
	else
	{

	}
}

static int	validate_coordinates(const char *line, int i)
{
	i++;
	if (!ft_isdigit(line[i]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		return (0);
	i++;
	if (!ft_isdigit(line[i]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != '\0')
		return (0);
	return (2);
}

//validate_line == 0 is invalid line, 1 is comment,
//2 is room and coordinates, 3 is link
static int	validate_line(const char *line, int i, int *room_type)
{
	if (line[0] == '#')
		return (1);
	while (ft_isalnum(line[i]))
		i++;
	if (line[i] == ' ')
	{
		if (validate_coordinates(line, i))
			return (2);
		return (0);
	}
	else if (line[i] == '-') // CHECK IF ROOM EXISTS!
	{
		i++;
		while (ft_isalnum(line[i]))
			i++;
		if (line[i] == '\0')
			return (3);
	}
	return (0);
}

//room_type == 0 is normal room, 1 is start room, 2 is end room
void	reader(t_graph *graph)
{
	t_reader	reader;

	reader.line = NULL;
	reader.room_type = 0;
	reader.total_rooms = 0;
	while (1)
	{
		reader.ret = get_next_line(0, &reader.line);
		if (reader.ret == -1)
			ft_error_exit("Error");
		else if (reader.ret == 0)
			break ;
		reader.line_type = validate_line(reader.line, 0, &reader.room_type);
		line_type_switch(graph, &reader);//line_type, &start_end, &total_rooms);
		free(reader.line);
	}
}

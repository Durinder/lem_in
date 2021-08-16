/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/16 18:35:11 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	line_type_switch(t_graph *graph, int line_type,
int	*start_end, int *total_rooms)
{
	if (line_type == 0)
		ft_error_exit("Error");
	else if (line_type == 1)
	{
		if (ft_strcmp("##start", line) == 0)
			*start_end = 1;
		else if (ft_strcmp("##end", line))
			*start_end = 2;
	}
	else if (line_type == 2)
		*total_rooms++;
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
//2 is link, 3 is room coordinates, 4 is start room,
//5 is end room
static int	validate_line(const char *line, int *start_end)
{
	int	i;

	if (line[0] == '#')
	{
		if (ft_strcmp("##start", line) == 0)
			*start_end == 1;
		if (ft_strcmp("##end", line) == 0)
			*start_end == 2;
		return (1);
	}
	i = 0;
	while (ft_isalnum(line[i]))
		i++;
	if (line[i] == ' ')
	{
		if (validate_coordinates(line, i))
			return (2);
		return (0);
	}
	else if (line[i] == '-')
	{
		i++;
		while (ft_isalnum(line[i]))
			i++;
		if (line[i] == '\0')
			return (3);
	}
	return (0);
}

//start_end = 1 is start room, 2 is end room
void	reader(t_graph *graph) //TEE TARKISTUSSTRUKTI
{
	int		ret;
	char	*line;
	int		line_type;
	int		start_end;
	int		total_rooms;

	ret = 0;
	line = NULL;
	start_end = 0;
	total_rooms = 0;
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			ft_error_exit("Error");
		else if (ret == 0)
			break ;
		line_type = validate_line(line, &start_end);
		line_type_switch(graph, line_type, &start_end, &total_rooms);
		free(line);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/30 15:39:14 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/* void	add_edge(t_graph *graph, char *src, char *dst)
{
	t_room	*cur;

	while (cur->next != NULL)
		cur = cur->next;
	cur->next = create_node(ft_strdup(name));
}
 */
t_room	*create_node(char *name)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new == NULL)
		ft_error_exit("Error: malloc.");
	new->name = name;
//	new->occupants = 0;
//	new->weight = 0;
	new->next = NULL;
	return (new);
}

void	realloc_graph(t_graph *graph)
{
	t_room	**new_list;
	size_t	new_size;
	size_t	i;

	new_size = graph->total_rooms + GRAPH_START_SIZE;
	new_list = (t_room **)malloc(sizeof(t_room *) * new_size);
	if (new_list == NULL)
		ft_error_exit("Error: malloc.");
	i = 0;
	while (i < graph->total_rooms)
	{
		new_list[i] = graph->adjlists[i];
		i++;
	}
	while (i < new_size)
		new_list[i++] = NULL;
	free(graph->adjlists);
	graph->adjlists = new_list;
}

t_graph	*create_graph(size_t vertices)
{
	t_graph	*graph;
	size_t	i;

	graph = (t_graph *)malloc(sizeof(t_graph));
	if (graph == NULL)
		ft_error_exit("Error: malloc.");
	graph->ants = 0;
	graph->total_rooms = 0;
	graph->start = 0;
	graph->end = 0;
	graph->adjlists = (t_room **)malloc(sizeof(t_room *) * vertices);
	if (graph->adjlists == NULL)
		ft_error_exit("Error: malloc.");
	i = 0;
	while (i < vertices)
		graph->adjlists[i++] = NULL;
	return (graph);
}

/* void	add_edge(t_graph *graph, char **rooms)
{
	t_room	*new;
	int		index;

	if (rooms[0] == NULL || rooms[1] == NULL)
		ft_error_exit("Error: malloc.");
	new = create_node(rooms[1]);
	index = connect_to(graph->adjlists, new, rooms[0]);
	graph->adjlists[index] = new;
	new = create_node(rooms[0]);
	index = connect_to(graph->adjlists, new, rooms[1]);
	graph->adjlists[index] = new;
	free(rooms[2]);
	free(rooms);
} */

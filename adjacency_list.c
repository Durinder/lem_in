/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:30 by vhallama          #+#    #+#             */
/*   Updated: 2021/08/16 16:06:58 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_node(char *name)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (new == NULL)
		ft_error_exit("Error: malloc.");
	new->name = ft_strdup(name);
	if (new->name == NULL)
		ft_error_exit("Error: malloc.");
	new->occupants = 0;
	new->weight = 0;
	new->type = 0;
	new->next = NULL;
	return (new);
}

t_graph	*create_graph(int vertices)
{
	t_graph	*graph;
	int		i;

	graph = (t_graph *)malloc(sizeof(t_graph));
	if (graph == NULL)
		ft_error_exit("Error: malloc.");
	graph->total_rooms = vertices;
	graph->adjlists = (t_room **)malloc(sizeof(t_room *) * vertices);
	if (graph->adjlists == NULL)
		ft_error_exit("Error: malloc.");
	while (i < vertices)
		graph->adjlists[i] = NULL;
	return (graph);
}

void	add_edge(t_graph *graph, char *room1, char *room2)
{
	t_room	*new;
	int		index;

	new = create_node(room2);
	index = connect_to(graph->adjlists, new, room1);
	graph->adjlists[index] = new;
	new = create_node(room1);
	index = connect_to(graph->adjlists, new, room2);
	graph->adjlists[index] = new;
}

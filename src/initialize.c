/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:23:02 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/08 14:20:01 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_init	get_t_init(void)
{
	t_init	init;

	init.line = NULL;
	init.ants = 0;
	init.ret = 0;
	init.start_check = 0;
	init.end_check = 0;
	init.start = 0;
	init.end = 0;
	init.total_rooms = 0;
	return (init);
}

t_graph	*initialize(void)
{
	t_graph		*graph;
	t_roomlist	*head;
	t_init		init;

	init = get_t_init();
	assign_ants(&init);
	head = create_roomlist_node(NULL);
	assign_rooms(&init, head, 0);
	if (init.start_check != 1 || init.end_check != 1 || \
			init.start == init.end || init.start == init.total_rooms || \
			init.end == init.total_rooms)
		ft_error_exit("Error: invalid start and/or end room(s).");
	while (head != NULL)
	{
		ft_printf("%s\n", head->name);
		head = head->next;
	}
	graph = create_graph(init, head);
/* 	while (init.ret > 0)
	{
		assign_links(graph, &init, 0, 0);
		ft_putendl(init.line);
		free(init.line);
		init.ret = get_next_line(0, &init.line);
		if (init.ret == -1)
			ft_error_exit("Error: reading.");
	}
	ft_putchar('\n'); */
	return (graph);
}

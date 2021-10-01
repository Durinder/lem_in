/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:07:12 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/01 18:04:13 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_roomlist	*create_roomlist_node(char *name, int *xy)
{
	t_roomlist	*new;

	new = ft_malloc_safe(sizeof(t_roomlist));
	new->name = name;
	if (xy)
	{
		new->xy[0] = xy[0];
		new->xy[1] = xy[1];
	}
	new->next = NULL;
	return (new);
}

void	push_back_roomlist(t_roomlist *head, char *name, int *xy)
{
	t_roomlist	*cur;

	if (name[0] == 'L')
		ft_error_exit("Error: room name starts with L.");
	if (head->name == NULL)
	{
		head->name = name;
		head->xy[0] = xy[0];
		head->xy[1] = xy[1];
	}
	else
	{
		cur = head;
		while (cur->next != NULL)
		{
			if (ft_strequ(cur->name, name))
				ft_error_exit("Error: duplicate room name.");
			cur = cur->next;
		}
		cur->next = create_roomlist_node(name, xy);
	}
	free(xy);
}

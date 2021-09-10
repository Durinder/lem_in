/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:07:12 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/10 13:07:12 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_roomlist	*create_roomlist_node(char *name, int *xy)
{
	t_roomlist	*new;

	new = ft_malloc_safe(sizeof(t_roomlist));
	new->name = name;
	new->xy[0] = xy[0];
	new->xy[1] = xy[1];
	new->next = NULL;
	return (new);
}

void	push_back_roomlist(t_roomlist *head, char *name, int *xy)
{
	t_roomlist	*cur;

	if (head->name == NULL)
		head->name = name;
	else
	{
		cur = head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = create_roomlist_node(name, xy);
	}
	free(xy);
}

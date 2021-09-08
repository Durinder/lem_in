/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:07:12 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/08 14:16:17 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_roomlist	*create_roomlist_node(char *name)
{
	t_roomlist	*new;

	new = ft_malloc_safe(sizeof(t_roomlist));
	new->name = name;
	new->next = NULL;
	return (new);
}

void	push_back(t_roomlist *head, char *name)
{
	t_roomlist	*cur;

	if (head->name == NULL)
		head->name = name;
	else
	{
		cur = head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = create_roomlist_node(name);
	}
}
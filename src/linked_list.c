/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:07:12 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/27 12:27:37 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	push_back_buffer(t_buffer *head, char *move)
{
	t_buffer	*new;
	t_buffer	*cur;

	new = ft_malloc_safe(sizeof(t_buffer));
	new->move = move;
	new->next = NULL;
	if (head->move == NULL)
		head->move = move;
	else
	{
		cur = head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}

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
			cur = cur->next;
		cur->next = create_roomlist_node(name, xy);
	}
	free(xy);
}

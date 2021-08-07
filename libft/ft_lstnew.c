/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:25:15 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/06 12:04:02 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	new_link = (t_list *)malloc(sizeof(t_list) * content_size);
	if (new_link == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		new_link->content = (void *)malloc(sizeof(content_size));
		if (new_link->content == NULL)
			return (NULL);
		ft_memcpy((void *)new_link->content, content, content_size);
		new_link->content_size = content_size;
	}
	new_link->next = NULL;
	return (new_link);
}

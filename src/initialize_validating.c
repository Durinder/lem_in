/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_validating.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:00:57 by vhallama          #+#    #+#             */
/*   Updated: 2021/09/10 13:24:10 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	check_for_duplicate_coordinates(t_roomlist *head, int *xy)
{
	t_roomlist	*cur;

	cur = head;
	while (cur != NULL)
	{
		if (cur->xy[0] == xy[0])
		{
			if (cur->xy[1] == xy[1])
				ft_error_exit("Error: duplicate room coordinates.");
		}
		cur = cur->next;
	}
}

int	*validate_coordinates(t_init *init, size_t i)
{
	size_t	xy[2];
	int		*ret;

	ret = ft_malloc_safe(sizeof(int) * 2);
	if (ft_isalnum(init->line[0]) == 0 || init->line[i++] != ' ')
		ft_error_exit("Error: invalid input line or missing coordinates.");
	if (ft_isdigit(init->line[i]) == 0)
		ft_error_exit("Error: invalid room coordinates.");
	xy[0] = ft_atoi_l(init->line + i);
	while (ft_isdigit(init->line[i]))
		i++;
	if (init->line[i++] != ' ' || xy[0] > INT_MAX)
		ft_error_exit("Error: invalid room coordinates.");
	if (ft_isdigit(init->line[i]) == 0)
		ft_error_exit("Error: invalid room coordinates.");
	xy[1] = ft_atoi_l(init->line + i);
	while (ft_isdigit(init->line[i]))
		i++;
	if (init->line[i] != '\0' || xy[1] > INT_MAX)
		ft_error_exit("Error: invalid room coordinates.");
	ret[0] = xy[0];
	ret[1] = xy[1];
	check_for_duplicate_coordinates(init->head, ret);
	ft_putendl(init->line);
	return (ret);
}

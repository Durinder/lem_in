/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:04:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/04 17:22:27 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_flags	*assign_flags(int argc, char **argv)
{
	t_flags	*flags;
	int		i;

	flags = ft_malloc_safe(sizeof(t_flags));
	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-d"))
			flags->depth = 1;
		else
		{
			ft_printf("Usage: './lem [flags] < map\noptional flags:\n");
			ft_printf("	-d	show depth of rooms\n");
			exit(0);
		}
		i++;
	}
	return (flags);
}

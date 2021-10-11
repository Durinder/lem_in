/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:04:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/10/08 18:21:23 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_flags	*assign_flags(int argc, char **argv)
{
	t_flags	*flags;
	int		i;

	flags = ft_malloc_safe(sizeof(t_flags));
	flags->depth = 0;
	flags->graph = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-d"))
			flags->depth = 1;
		else if (ft_strequ(argv[i], "-g"))
			flags->graph = 1;
		else if (ft_strequ(argv[i], "-f"))
			flags->flow = 1;
		else
		{
			ft_printf("Usage: ./lem [flags] < map\noptional flags:\n");
			ft_printf("	-d	show depth of rooms\n");
			ft_printf("	-g	print graph\n");
			exit(0);
		}
		i++;
	}
	return (flags);
}

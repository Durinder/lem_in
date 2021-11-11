/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhallama <vhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:04:55 by vhallama          #+#    #+#             */
/*   Updated: 2021/11/11 14:25:56 by vhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_pathing(t_room *start)
{
	t_room	*cur;
	int		i;

	write(1, "\n", 1);
	if (start->output)
		ft_printf("%s(0)\n", start->output->name);
	i = 0;
	while (i < start->links)
	{
		if (start->link[i]->input)
		{
			cur = start->link[i];
			while (cur)
			{
				ft_printf("%s(%d)", cur->name, cur->depth);
				cur = cur->output;
				if (cur)
					ft_printf("->");
			}
			write(1, "\n", 1);
		}
		i++;
	}
}

static void	print_usage(void)
{
	ft_printf("Usage: ./lem [flags] < map\noptional flags:\n");
	ft_printf("	-p	show paths for current amount of ants\n");
	ft_printf("	-l	show amount of lines of given solutiuon\n");
	exit(0);
}

t_flags	*assign_flags(int argc, char **argv)
{
	t_flags	*flags;
	int		i;

	if (argc > 2 || argv[1][0] != '-' || argv[1][1] == '\0')
		print_usage();
	flags = ft_malloc_safe(sizeof(t_flags));
	i = 1;
	while (argv[1][i])
	{
		if (argv[1][i] == 'p')
			flags->path = 1;
		else if (argv[1][i] == 'l')
			flags->lines = 1;
		else
			print_usage();
		i++;
	}
	return (flags);
}

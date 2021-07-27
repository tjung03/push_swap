
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/07/17 01:08:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_global	g;

	ft_memset(&g, 0, sizeof(t_global));
	if (ac > 1)
	{
		if (!get_arguments(ac, av, &g.stack_a))
			return (free_list(1, &g));
		stack_location(g.stack_a, &g.loc_a);
		if (!sort_ascending(&g))
			return (free_list(1, &g));
		delete_unnecessary_commands(&g.cmd);
		print_num_cmds(g.cmd);
	}
	return (free_list(0, &g));
}

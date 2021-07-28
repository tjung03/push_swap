/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:36:56 by tjung             #+#    #+#             */
/*   Updated: 2021/07/29 03:37:02 by tjung            ###   ########.fr       */
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

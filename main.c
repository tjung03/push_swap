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

	g.stack_a = NULL;
	g.stack_b = NULL;
	if (ac > 1)
	{
		ft_memset(&g.loc_a, 0, sizeof(t_locate));
		ft_memset(&g.loc_b, 0, sizeof(t_locate));
		if (!get_arguments(ac, av, &g.stack_a))
			return (free_list(1, g.stack_a, g.stack_b));
		stack_location(g.stack_a, &g.loc_a);
		if (!sort_ascending(&g))
			return (free_list(1, g.stack_a, g.stack_b));
	}
	return (free_list(0, g.stack_a, g.stack_b));
}

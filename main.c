/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:34:54 by tjung             #+#    #+#             */
/*   Updated: 2021/07/07 19:11:46 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_env(char *av)
{
	int	idx;

	idx = 0;
	while (av[idx])
	{
		if (av[idx] < 48 && av[idx] > 57)
			return (1);
		idx++;
	}
	return (0);
}

int	check_arguments(char **av)
{
	char	**split;
	int		idx;

	idx = 0;
	while (av[++idx])
	{
		if (check_env(av[idx])
		{
			split = ft_split(av[idx]);
		}
	}
	// no Integer : is_int();
	// no Integer range : is_int_range();
	// Duplicates : is_dup();
}

int	main(int ac, char **av)
{
	t_list			stack_a;
	t_list			stack_b;
	t_conditions	cdt;

	ft_memset(&stack_a, 0, sizeof(t_list));
	ft_memset(&stack_b, 0, sizeof(t_list));
	ft_memset(&cdt, 0, sizeof(t_conditions));
	if (check_arguments(av))
		// error
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:31:26 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:31:28 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	creat_list(char **arg, t_list **stack, int idx, int env)
{
	char	**temp;
	int		data;

	temp = NULL;
	if (env == 1)
		temp = arg;
	data = 0;
	if (!is_valid_int(arg[idx], &data))
		return (free_split(0, temp));
	if (!(*stack))
	{
		*stack = ft_lst_new(data);
		if (!(*stack))
			return (free_split(0, temp));
	}
	else
	{
		if (!ft_lst_add_back(*stack, data))
			return (free_split(0, temp));
		if (is_dup(*stack))
			return (free_split(0, temp));
	}
	return (1);
}

int	get_arguments(int ac, char **av, t_list **stack)
{
	char	**split;
	int		i;
	int		j;

	split = NULL;
	i = ac;
	while (--i > 0)
	{
		if (check_env(av[i]))
		{
			split = ft_split(av[i]);
			if (!split)
				return (0);
			j = -1;
			while (split[++j])
				if (!creat_list(split, stack, j, 1))
					return (0);
		}
		else
		{
			if (!creat_list(av, stack, i, 0))
				return (0);
		}
	}
	return (free_split(1, split));
}

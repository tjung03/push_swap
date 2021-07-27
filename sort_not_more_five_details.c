/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_not_more_five_details.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 03:56:39 by marvin            #+#    #+#             */
/*   Updated: 2021/07/28 08:04:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	no_max_top(t_global *g, int middle)
{
	if (middle < (g->stack_a)->data)
	{
		if (!execute_cmds(g, 1))
			return (0);
	}
	else
	{
		if (!execute_cmds(g, 9))
			return (0);
	}
	return (1);
}

static int	max_top(t_global *g, int middle)
{
	if (middle < (g->stack_a)->data)
	{
		if (!execute_cmds(g, 6))
			return (0);
	}
	else
	{
		if (!execute_cmds(g, 1))
			return (0);
		if (!execute_cmds(g, 9))
			return (0);
	}
	return (1);
}

int	top_isnt_min_in_three(t_global *g)
{
	int	middle;

	middle = ((g->stack_a)->next)->data;
	if (!top_is_max(g))
	{
		if (!no_max_top(g, middle))
			return (0);
	}
	else
	{
		if (!max_top(g, middle))
			return (0);
	}
	return (1);
}

static int	move_according_to_idx(t_global *g, int size, int idx)
{
	if (idx == 2)
	{
		if (!execute_cmds(g, 1))
			return (0);
	}
	else if (idx == 3)
	{
		if (!execute_cmds(g, 6))
			return (0);
		if (!execute_cmds(g, 1))
			return (0);
	}
	else if (idx == 4)
	{
		if (!execute_cmds(g, 9))
			return (0);
		if (size == 5)
			if (!execute_cmds(g, 9))
				return (0);
	}
	else if (idx == 5)
		if (!execute_cmds(g, 9))
			return (0);
	return (1);
}

int	raise_one_to_top_in_five(t_global *g, int idx)
{
	int	size;

	size = ft_lst_size(g->stack_a);
	if (!move_according_to_idx(g, size, idx))
		return (0);
	return (1);
}

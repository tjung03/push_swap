/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_not_more_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:31:59 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:32:00 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_three(t_global *g)
{
	if (top_is_min(g))
	{
		if (!execute_cmds(g, 1))
			return (0);
		if (!execute_cmds(g, 6))
			return (0);
	}
	else
	{
		if (!top_isnt_min_in_three(g))
			return (0);
	}
	return (1);
}

static int	sort_four(t_global *g, int size)
{
	int	min_idx;

	min_idx = what_min_idx(&g->loc_a);
	if (!raise_one_to_top_in_five(g, min_idx))
		return (0);
	if (!check_a_ascending(g, size))
	{
		if (!execute_cmds(g, 5))
			return (0);
		if (!sort_three(g))
			return (0);
		if (!execute_cmds(g, 4))
			return (0);
	}
	return (1);
}

static int	sort_five(t_global *g, int size)
{
	int	idx;

	idx = what_min_idx(&g->loc_a);
	if (!raise_one_to_top_in_five(g, idx))
		return (0);
	if (!check_a_ascending(g, size))
	{
		if (!execute_cmds(g, 5))
			return (0);
		idx = what_max_idx(&g->loc_a);
		if (!raise_one_to_top_in_five(g, idx))
			return (0);
		if (!execute_cmds(g, 5))
			return (0);
		if (!check_a_ascending(g, size))
			if (!sort_three(g))
				return (0);
		if (!execute_cmds(g, 4))
			return (0);
		if (!execute_cmds(g, 6))
			return (0);
		if (!execute_cmds(g, 4))
			return (0);
	}
	return (1);
}

int	sort_not_more_five(t_global *g, int size)
{
	if (!check_a_ascending(g, size))
	{
		if (size == 2)
		{
			if (!execute_cmds(g, 1))
				return (0);
		}
		else if (size == 3)
		{
			if (!sort_three(g))
				return (0);
		}
		else if (size == 4)
		{
			if (!sort_four(g, size))
				return (0);
		}
		else
		{
			if (!sort_five(g, size))
				return (0);
		}
	}
	return (1);
}

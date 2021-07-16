/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_not_more_than_five.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:51:07 by marvin            #+#    #+#             */
/*   Updated: 2021/07/16 21:07:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_three(t_global *g)
{
	int	middle;
	
	if (top_is_min(g))
	{
		swap_stack(&g->stack_a, &g->loc_a, 'a');
		rotate_stack(&g->stack_a, &g->loc_a, 'a');
	}
	else
		top_isnt_min_in_three(g);
	middle = ((g->stack_a)->next)->data;
	return (middle);
}

static void	sort_four(t_global *g)
{
	int	min_idx;

	min_idx = what_min_idx(&g->loc_a);
	raise_one_to_top_in_five(g, min_idx);
	if (!check_ascending(g))
	{
		push_stack_b(g);
		sort_three(g);
		push_stack_a(g);
	}
}

static void	sort_five(t_global *g)
{
	int	min_idx;
	int	max_idx;

	min_idx = what_min_idx(&g->loc_a);
	raise_one_to_top_in_five(g, min_idx);
	if (!check_ascending(g))
	{
		push_stack_b(g);
		max_idx = what_max_idx(&g->loc_a);
		raise_one_to_top_in_five(g, max_idx);
		push_stack_b(g);
		if (!check_ascending(g))
			sort_three(g);
		push_stack_a(g);
		rotate_stack(&g->stack_a, &g->loc_a, 'a');
		push_stack_a(g);
	}
}

void		sort_not_more_than_five(t_global *g, int size)
{
	if (!check_ascending(g))
	{
		if (size == 2)
			swap_stack(&g->stack_a, &g->loc_a, 'a');
		else if (size == 3)
			sort_three(g);
		else if (size == 4)
			sort_four(g);
		else
			sort_five(g);
	}
}

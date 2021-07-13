/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_details.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 03:56:39 by marvin            #+#    #+#             */
/*   Updated: 2021/07/14 04:11:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_isnt_min_in_three(t_global *g)
{
	int	middle;

	middle = ((g->stack_a)->next)->data;
	if (!top_is_max(g))
	{
		if (middle < (g->stack_a)->data)
			swap_stack(&g->stack_a, &g->loc_a, 'a');
		else
			reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
	}
	else
	{
		if (middle < (g->stack_a)->data)
			rotate_stack(&g->stack_a, &g->loc_a, 'a');
		else
		{
			swap_stack(&g->stack_a, &g->loc_a, 'a');
			reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
		}
	}
}

void	raise_one_to_top_in_five(t_global *g, int idx)
{
	int	size;

	size = ft_lst_size(g->stack_a);
	if (idx == 2)
		swap_stack(&g->stack_a, &g->loc_a, 'a');
	else if (idx == 3)
	{
		rotate_stack(&g->stack_a, &g->loc_a, 'a');
		swap_stack(&g->stack_a, &g->loc_a, 'a');
	}
	else if (idx == 4)
	{
		reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
		if (size == 5)
			reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
	}
	else if (idx == 5)
		reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
}

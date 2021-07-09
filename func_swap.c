/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:42:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/10 02:29:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both_stack(t_global *g, char stack)
{
	swap_stack(&g->loc_a, stack);
	swap_stack(&g->loc_b, stack);
	if (stack == 's')
		write(1, "ss\n", 3);
}

void	swap_stack(t_locate *loc, char stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = loc->top;
	second = first->prev;
	third = second->prev;
	first->next = second;
	first->prev = third;
	second->next = NULL;
	second->prev = first;
	third->next = first;
	loc->top = second;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else if (stack == 'b')
		write(1, "sb\n", 3);
}

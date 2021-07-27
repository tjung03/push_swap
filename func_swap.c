/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:42:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/28 04:20:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_swap_kind(char kind)
{
	if (kind == 'a')
		return (1);
	else if (kind == 'b')
		return (2);
	return (-1);
}

int	swap_both_stack(t_global *g, char kind)
{
	swap_stack(&g->stack_a, &g->loc_a, kind);
	swap_stack(&g->stack_b, &g->loc_b, kind);
	if (kind == 's')
		return (3);
	return (-1);
}

int	swap_stack(t_list **stack, t_locate *loc, char kind)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (loc->bottom && (ft_lst_size(loc->bottom) > 1))
	{
		first = loc->top;
		second = first->prev;
		third = second->prev;
		first->next = second;
		first->prev = third;
		second->next = NULL;
		second->prev = first;
		if (third)
			third->next = first;
		if (ft_lst_size(loc->bottom) == 2)
		{
			*stack = first;
			loc->bottom = *stack;
		}
		loc->top = second;
		return (print_swap_kind(kind));
	}
	return (-1);
}

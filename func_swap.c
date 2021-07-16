/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:42:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/14 05:34:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_swap_kind(char kind)
{
	if (kind == 'a')
		write(1, "sa\n", 3);
	else if (kind == 'b')
		write(1, "sb\n", 3);
}

void	swap_both_stack(t_global *g, char kind)
{
	swap_stack(&g->stack_a, &g->loc_a, kind);
	swap_stack(&g->stack_b, &g->loc_b, kind);
	if (kind == 's')
		write(1, "ss\n", 3);
}

void	swap_stack(t_list **stack, t_locate *loc, char kind)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	int		size;

	size = ft_lst_size(loc->bottom);
	if (loc->bottom && (size > 1))
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
		if (size == 2)
		{
			*stack = first;
			loc->bottom = *stack;
		}
		loc->top = second;
		print_swap_kind(kind);
	}
}

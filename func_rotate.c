/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:27:42 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:27:44 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_rotate_kind(char kind)
{
	if (kind == 'a')
		return (6);
	else if (kind == 'b')
		return (7);
	return (-1);
}

int	rotate_both_stack(t_global *g, char kind)
{
	rotate_stack(&g->stack_a, &g->loc_a, kind);
	rotate_stack(&g->stack_b, &g->loc_b, kind);
	if (kind == 'r')
		return (8);
	return (-1);
}

int	rotate_stack(t_list **stack, t_locate *loc, char kind)
{
	t_list	*above;
	t_list	*below;
	t_list	*temp;
	int		size;

	size = ft_lst_size(*stack);
	if (*stack && (size > 1))
	{
		above = loc->top;
		below = loc->bottom;
		temp = above->prev;
		temp->next = NULL;
		above->prev = NULL;
		above->next = below;
		below->prev = above;
		*stack = above;
		loc->bottom = *stack;
		loc->top = temp;
		return (print_rotate_kind(kind));
	}
	return (-1);
}

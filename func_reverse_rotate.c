/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:24:26 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:24:29 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_reverse_rotate_kind(char kind)
{
	if (kind == 'a')
		return (9);
	else if (kind == 'b')
		return (10);
	return (-1);
}

int	reverse_rotate_both_stack(t_global *g, char kind)
{
	reverse_rotate_stack(&g->stack_a, &g->loc_a, kind);
	reverse_rotate_stack(&g->stack_b, &g->loc_b, kind);
	if (kind == 'r')
		return (11);
	return (-1);
}

int	reverse_rotate_stack(t_list **stack, t_locate *loc, char kind)
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
		temp = below->next;
		temp->prev = NULL;
		below->next = NULL;
		below->prev = above;
		above->next = below;
		*stack = temp;
		loc->bottom = *stack;
		loc->top = below;
		return (print_reverse_rotate_kind(kind));
	}
	return (-1);
}

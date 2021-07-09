/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:42:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/10 07:01:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_stack(t_global *g, char kind)
{
	rotate_stack(&g->stack_a, &g->loc_a, kind);
	rotate_stack(&g->stack_b, &g->loc_b, kind);
	if (kind == 'r')
		write(1, "rr\n", 3);
}

void	rotate_stack(t_list **stack, t_locate *loc, char kind)
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
		if (kind == 'a')
			write(1, "ra\n", 3);
		else if (kind == 'b')
			write(1, "rb\n", 3);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:42:30 by marvin            #+#    #+#             */
/*   Updated: 2021/07/10 07:23:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	have_stack_b(t_global *g, t_list **first_b, t_list **first_a)
{
	if (g->stack_b)
		*first_b = (g->loc_b).top;
	else
	{
		g->stack_b = *first_a;
		(g->loc_b).top = g->stack_b;
		(g->loc_b).bottom = g->stack_b;
	}
}

static void	have_prev_stack_a(t_global *g, t_list **first_a, t_list **second_a)
{
	if ((*first_a)->prev)
	{
		*second_a = (*first_a)->prev;
		(*second_a)->next = NULL;
		(g->loc_a).top = *second_a;
	}
	else
	{
		g->stack_a = NULL;
		(g->loc_a).top = NULL;
		(g->loc_a).bottom = NULL;
	}
}

void	push_stack_b(t_global *g)
{
	t_list	*first_b;
	t_list	*first_a;
	t_list	*second_a;

	if (g->stack_a)
	{
		first_a = (g->loc_a).top;
		have_stack_b(g, &first_b, &first_a);
		have_prev_stack_a(g, &first_a, &second_a);
		if (g->stack_b == first_a)
		{
			first_a->next = NULL;
			first_a->prev = NULL;
		}
		else
		{
			first_a->prev = first_b;
			first_b->next = first_a;
			(g->loc_b).top = first_a;
		}
		write(1, "pb\n", 3);
	}
}

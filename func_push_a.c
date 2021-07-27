/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:35:00 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:35:01 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	have_stack_a(t_global *g, t_list **first_a, t_list **first_b)
{
	if (g->stack_a)
		*first_a = (g->loc_a).top;
	else
	{
		g->stack_a = *first_b;
		(g->loc_a).top = g->stack_a;
		(g->loc_a).bottom = g->stack_a;
	}
}

static void	have_prev_stack_b(t_global *g, t_list **first_b, t_list **second_b)
{
	if ((*first_b)->prev)
	{
		*second_b = (*first_b)->prev;
		(*second_b)->next = NULL;
		(g->loc_b).top = *second_b;
	}
	else
	{
		g->stack_b = NULL;
		(g->loc_b).top = NULL;
		(g->loc_b).bottom = NULL;
	}
}

int	push_stack_a(t_global *g)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*second_b;

	if (g->stack_b)
	{
		first_b = (g->loc_b).top;
		have_stack_a(g, &first_a, &first_b);
		have_prev_stack_b(g, &first_b, &second_b);
		if (g->stack_a == first_b)
		{
			first_b->next = NULL;
			first_b->prev = NULL;
		}
		else
		{
			first_b->prev = first_a;
			first_a->next = first_b;
			(g->loc_a).top = first_b;
		}
		return (4);
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:35:12 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:35:13 by tjung            ###   ########.fr       */
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

int	push_stack_b(t_global *g)
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
		return (5);
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:41:10 by marvin            #+#    #+#             */
/*   Updated: 2021/07/26 19:18:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a_ascending(t_global *g, int size)
{
	t_list	*curr;
	int		check_point;
	int		comparison_target;

	curr = (g->loc_a).top;
	if (g->stack_a)
	{
		while (curr->prev && --size)
		{
			check_point = curr->data;
			curr = curr->prev;
			comparison_target = curr->data;
			if (check_point > comparison_target)
				return (0);
		}
	}
	return (1);
}

int	check_b_descending(t_global *g, int size)
{
	t_list	*curr;
	int		check_point;
	int		comparison_target;

	curr = (g->loc_b).top;
	if (g->stack_b)
	{
		while (curr->prev && --size)
		{
			check_point = curr->data;
			curr = curr->prev;
			comparison_target = curr->data;
			if (check_point < comparison_target)
				return (0);
		}
	}
	return (1);
}

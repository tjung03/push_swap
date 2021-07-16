/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five_details.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:12:40 by marvin            #+#    #+#             */
/*   Updated: 2021/07/16 20:58:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_size_for_b(t_global *g)
{
	t_list	*top_a;
	t_list	*curr_b;
	int		max_b;
	int		min_b;

	top_a = (g->loc_a).top;
	curr_b = (g->loc_b).top;
	max_b = curr_b->data;
	min_b = curr_b->data;
	while (curr_b)
	{
		if (max_b < curr_b->data)
			max_b = curr_b->data;
		if (min_b > curr_b->data)
			min_b = curr_b->data;
		curr_b = curr_b->prev;
	}
	if (top_a->data > max_b)
		return (1);
	else if (top_a->data < min_b)
		return (-1);
	return (0);
}

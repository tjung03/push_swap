/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five_details.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:12:40 by marvin            #+#    #+#             */
/*   Updated: 2021/07/17 02:26:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_if_chunk(t_global *g, int *chunks, int level)
{
	t_list	*curr;

	curr = (g->loc_a).top;
	while (curr)
	{
		if (level == 1)
		{
			if (curr->data == chunks[0])
				return (1);
		}
		if (curr->data > chunks[level - 1] && curr->data <= chunks[level])
			return (1);
		curr = curr->prev;
	}
	return (0);
}

int	get_distance_stack_a(t_global *g, int *chunks, int level)
{
	t_list	*curr;
	int		cnt;

	curr = (g->loc_a).top;
	cnt = 1;
	while (curr)
	{
		if (level == 1)
		{
			if (curr->data == chunks[0])
				break ;
		}
		if (curr->data > chunks[level - 1] && curr->data <= chunks[level])
			break ;
		cnt++;
		curr = curr->prev;
	}
	return (cnt);
}

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

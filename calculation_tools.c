/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 02:08:58 by marvin            #+#    #+#             */
/*   Updated: 2021/07/14 03:55:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	what_max_idx(t_locate *loc)
{
	t_list	*curr;
	int		cnt;
	int		temp;
	int		max;

	curr = loc->top;
	max = curr->data;
	while (curr->prev)
	{
		curr = curr->prev;
		temp = curr->data;
		if (max < temp)
			max = temp;
	}
	curr = loc->top;
	cnt = 1;
	while (curr)
	{
		if (max == curr->data)
			break ;
		cnt++;
		curr = curr->prev;
	}
	return (cnt);
}

int	what_min_idx(t_locate *loc)
{
	t_list	*curr;
	int		cnt;
	int		temp;
	int		min;

	curr = loc->top;
	min = curr->data;
	while (curr->prev)
	{
		curr = curr->prev;
		temp = curr->data;
		if (min > temp)
			min = temp;
	}
	curr = loc->top;
	cnt = 1;
	while (curr)
	{
		if (min == curr->data)
			break ;
		cnt++;
		curr = curr->prev;
	}
	return (cnt);
}

int	top_is_min(t_global *g)
{
	t_list	*curr;
	int		min;

	curr = (g->loc_a).top;
	min = curr->data;
	while (curr->prev)
	{
		curr = curr->prev;
		if (min > curr->data)
			return (0);
	}
	return (1);
}

int	top_is_max(t_global *g)
{
	t_list	*curr;
	int		max;

	curr = (g->loc_a).top;
	max = curr->data;
	while (curr->prev)
	{
		curr = curr->prev;
		if (max < curr->data)
			return (0);
	}
	return (1);
}

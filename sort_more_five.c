/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:01:15 by marvin            #+#    #+#             */
/*   Updated: 2021/07/17 02:26:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	raise_chunk_to_top(t_global *g, int size_a, int position)
{
	if (position <= size_a / 2)
	{
		while (--position)
			rotate_stack(&g->stack_a, &g->loc_a, 'a');
	}
	else
	{
		while ((size_a + 1) - position++)
			reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
	}
}

static void	find_loc_stack_b(t_global *g, int size_b, int *comp, int *dist)
{
	int	move;
	int	restore;

	*comp = compare_size_for_b(g);
	if (!(*comp))
	{
		*dist = get_distance_stack_b(g, size_b);
		move = *dist;
		restore = size_b - move;
		if (move <= restore)
		{
			while (move--)
				rotate_stack(&g->stack_b, &g->loc_b, 'b');
		}
		else
		{
			move = restore;
			while (move--)
				reverse_rotate_stack(&g->stack_b, &g->loc_b, 'b');
		}
	}
}

static void	restore_to_stack_a(t_global *g, int size_b, int comp, int dist)
{
	int move;
	int restore;

	move = dist;
	restore = size_b - move;
	if (comp == -1)
		rotate_stack(&g->stack_b, &g->loc_b, 'b');
	else if (!comp)
	{
		if (move <= restore)
		{
			while (move--)
				reverse_rotate_stack(&g->stack_b, &g->loc_b, 'b');
		}
		else
		{
			move = restore;
			rotate_stack(&g->stack_b, &g->loc_b, 'b');
			while (move--)
				rotate_stack(&g->stack_b, &g->loc_b, 'b');
		}
	}
}

static void	adjust_level(t_global *g, int size_a, int *chunks, int *level)
{
	int	size_b;
	int	compare;
	int	distance;
	
	if (find_if_chunk(g, chunks, *level))
	{
		raise_chunk_to_top(g, size_a, get_distance_stack_a(g, chunks, *level));
		size_b = ft_lst_size(g->stack_b);
		if (g->stack_b)
			find_loc_stack_b(g, size_b, &compare, &distance);
		if (!(check_ascending(g) && check_descending(g)))
		{
			if (!(compare == 1 && size_a == 1))
				push_stack_b(g);
			restore_to_stack_a(g, size_b, compare, distance);
		}
		else
		{
			while (size_b--)
				push_stack_a(g);
			return ;
		}
	}
	else
		(*level)++;
}

int	sort_more_five(t_global *g, int size_a, int *chunks, int zone)
{
	int	level;
	int	size_b;

	chunks = (int *)malloc(sizeof(int) * zone + 1);
	if (!chunks)
		return (0);
	size_a = ft_lst_size(g->stack_a);
	if (divide_chunks(g, chunks, size_a, zone))
	{
		level = 1;
		while (level < zone + 1)
			adjust_level(g, size_a, chunks, &level);
		size_b = ft_lst_size(g->stack_b);
		while (size_b--)
			push_stack_a(g);
	}
	return (1);
}

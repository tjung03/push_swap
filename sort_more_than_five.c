/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:01:15 by marvin            #+#    #+#             */
/*   Updated: 2021/07/16 21:40:40 by marvin           ###   ########.fr       */
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

int	get_distance(t_global *g, int *chunks, int level)
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

void	sort_more_than_five(t_global *g, int size_a, int zone)
{
	int	chunks[zone + 1];
	int	size_b;
	int	level;
	int	position;
	int	compare;
	int	cnt;
	int	move;
	int	restore;

	size_a = ft_lst_size(g->stack_a);
	compare = 1;
	if (divide_chunks(g, chunks, size_a, zone))
	{
		level = 1;
		while (level < zone + 1)
		{
			if (find_if_chunk(g, chunks, level))
			{
				position = get_distance(g, chunks, level);
				if (position <= size_a / 2)
					while (--position)
						rotate_stack(&g->stack_a, &g->loc_a, 'a');
				else
					while ((size_a + 1) - position++)
						reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
				size_b = ft_lst_size(g->stack_b);
				if (g->stack_b)
				{
					compare = compare_size_for_b(g);
					if (size_b > 1 && !compare)
					{
						cnt = find_correct_loc_stack_b(g, size_b);
						move = cnt;
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
				if (!(check_ascending(g) && check_descending(g)))
				{
					if (!(compare == 1 && size_a == 1))
						push_stack_b(g);
					if (compare == -1)
						rotate_stack(&g->stack_b, &g->loc_b, 'b');
					else if (!compare)
					{
						move = cnt;
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
				else
				{
					while (size_b--)
						push_stack_a(g);
					return ;
				}
			}
			else
				level++;
		}
		size_b = ft_lst_size(g->stack_b);
		while (size_b--)
			push_stack_a(g);
	}
}

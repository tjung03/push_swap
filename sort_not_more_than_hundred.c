/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_not_more_than_hundred.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:01:15 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 03:50:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_if_chunk(t_global *g, int *chunks, int level)
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

int		get_distance(t_global *g, int *chunks, int level)
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
			break;
		cnt++;
		curr = curr->prev;
	}
	return (cnt);
}

void	sort_not_more_than_hundred(t_global *g)
{
	int	chunks[6];
	int	size;
	int	level;
	int	position;

	size = ft_lst_size(g->stack_a);
	if (divide_chunks(g, chunks, size, 5))
	{
		level = 1;
		while (level < 6)
		{
			if (find_if_chunk(g, chunks, level))
			{
				position = get_distance(g, chunks, level);
				if (position <= size / 2)
					while (--position)
						rotate_stack(&g->stack_a, &g->loc_a, 'a');
				else
					while ((size + 1) - position++)
						reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
				push_stack_b(g);
				if (!check_descending(g))
				{
					// stack_b 내림차순 정렬
				}
			}
			else
				level++;
		}
	}
}

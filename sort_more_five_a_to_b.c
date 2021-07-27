/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five_a_to_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:27:58 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:27:59 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	recover_chunks_ab(t_global *g, t_sortool *t)
{
	t->re_cnt = find_min_cnt(t->ra_cnt, t->rb_cnt);
	while ((t->re_cnt)--)
	{
		if (!execute_cmds(g, 11))
			return (0);
	}
	if (t->ra_cnt <= t->rb_cnt)
	{
		t->re_cnt = t->rb_cnt - t->ra_cnt;
		while ((t->re_cnt)-- > 0)
		{
			if (!execute_cmds(g, 10))
				return (0);
		}
	}
	else
	{
		t->re_cnt = t->ra_cnt - t->rb_cnt;
		while ((t->re_cnt)--)
		{
			if (!execute_cmds(g, 9))
				return (0);
		}
	}
	return (1);
}

static int	classify_chunks_ab(t_global *g, t_sortool *t, int size)
{
	while (size--)
	{
		if (((g->loc_a).top)->data >= t->pivot[1])
		{
			if (!execute_cmds(g, 6))
				return (0);
			(t->ra_cnt)++;
		}
		else
		{
			if (!execute_cmds(g, 5))
				return (0);
			(t->pb_cnt)++;
			if (((g->loc_b).top)->data >= t->pivot[0])
			{
				if (!execute_cmds(g, 7))
					return (0);
				(t->rb_cnt)++;
			}
		}
	}
	return (1);
}

static int	not_more_three_ab(t_global *g, t_sortool *t, int size)
{
	if (!check_a_ascending(g, size))
	{
		if (!execute_cmds(g, 1))
			return (free_sortool(0, t));
	}
	return (1);
}

int	sort_a_to_b(t_global *g, int size)
{
	t_sortool	*t;

	t = (t_sortool *)malloc(sizeof(t_sortool));
	if (!t)
		return (0);
	ft_memset(t, 0, sizeof(t_sortool));
	if (size < 3)
		return (not_more_three_ab(g, t, size));
	t->pivot = get_pivot(&g->loc_a, size);
	if (!(t->pivot))
		return (free_sortool(0, t));
	if (!classify_chunks_ab(g, t, size))
		return (free_sortool(0, t));
	if (!recover_chunks_ab(g, t))
		return (free_sortool(0, t));
	free(t->pivot);
	if (!sort_a_to_b(g, t->ra_cnt))
		return (free_sortool(0, t));
	if (!sort_b_to_a(g, t->rb_cnt))
		return (free_sortool(0, t));
	if (!sort_b_to_a(g, t->pb_cnt - t->rb_cnt))
		return (free_sortool(0, t));
	free(t);
	return (1);
}

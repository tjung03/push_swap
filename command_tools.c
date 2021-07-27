/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 03:46:08 by marvin            #+#    #+#             */
/*   Updated: 2021/07/28 06:44:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	save_cmds(t_global *g, int num)
{
	t_command	*curr;
	t_command	*temp;
	
	if (!(g->cmd))
	{
		g->cmd = (t_command *)malloc(sizeof(t_command));
		if (!(g->cmd))
			return (0);
		(g->cmd)->v = num;
		(g->cmd)->next = NULL;
	}
	else
	{
		curr = g->cmd;
		while (curr->next)
			curr = curr->next;
		temp = (t_command *)malloc(sizeof(t_command));
		if (!temp)
			return (0);
		curr->next = temp;
		temp->v = num;
		temp->next = NULL;
		temp = NULL;
	}
	return (1);
}

static void	execute_r_rotate(t_global *g, int num, int *ok)
{
	if (num == 9)
		*ok = save_cmds(g, reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a'));
	else if (num == 10)
		*ok = save_cmds(g, reverse_rotate_stack(&g->stack_b, &g->loc_b, 'b'));
	else if (num == 11)
		*ok = save_cmds(g, reverse_rotate_both_stack(g, 'r'));
}

static void	execute_rotate(t_global *g, int num, int *ok)
{
	if (num == 6)
		*ok = save_cmds(g, rotate_stack(&g->stack_a, &g->loc_a, 'a'));
	else if (num == 7)
		*ok = save_cmds(g, rotate_stack(&g->stack_b, &g->loc_b, 'b'));
	else if (num == 8)
		*ok = save_cmds(g, rotate_both_stack(g, 'r'));
}

static void	execute_swap(t_global *g, int num, int *ok)
{
	if (num == 1)
		*ok = save_cmds(g, swap_stack(&g->stack_a, &g->loc_a, 'a'));
	else if (num == 2)
		*ok = save_cmds(g, swap_stack(&g->stack_b, &g->loc_b, 'b'));
	else if (num == 3)
		*ok = save_cmds(g, swap_both_stack(g, 's'));
}

int	execute_cmds(t_global *g, int num)
{
	int	ok;
	
	ok = 1;
	if (num >= 1 && num <= 3)
		execute_swap(g, num, &ok);
	else if (num == 4)
		ok = save_cmds(g, push_stack_a(g));
	else if (num == 5)
		ok = save_cmds(g, push_stack_b(g));
	else if (num >= 6 && num <= 8)
		execute_rotate(g, num, &ok);
	else if (num >= 9 && num <= 11)
		execute_r_rotate(g, num, &ok);
	if (!ok)
		return (0);
	return (1);
}

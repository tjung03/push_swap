/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:33:29 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:33:30 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_value_two_nodes(t_command **cur, t_command **nxt, int num)
{
	if (num == 8)
	{
		(*cur)->v = 8;
		(*nxt)->v = -1;
	}
	else if (num == 11)
	{
		(*cur)->v = 11;
		(*nxt)->v = -1;
	}
}

static void	change_values_two_nodes(t_command **cur, t_command **nxt)
{
	(*cur)->v = -1;
	(*nxt)->v = -1;
}

void	delete_unnecessary_commands(t_command **cmd)
{
	t_command	*c;
	t_command	*n;

	c = *cmd;
	while (c)
	{
		n = c->next;
		if (n)
		{
			if ((c->v == 6 && n->v == 9) || (c->v == 9 && n->v == 6)
				|| (c->v == 7 && n->v == 10) || (c->v == 10 && n->v == 7)
				|| (c->v == 4 && n->v == 5) || (c->v == 5 && n->v == 4)
				|| (c->v == 1 && n->v == 1)
				|| (c->v == 2 && n->v == 2)
				|| (c->v == 3 && n->v == 3)
				|| (c->v == 8 && n->v == 11) || (c->v == 11 && n->v == 8))
				change_values_two_nodes(&c, &n);
			else if ((c->v == 6 && n->v == 7) || (c->v == 7 && n->v == 6))
				change_value_two_nodes(&c, &n, 8);
			else if ((c->v == 9 && n->v == 10) || (c->v == 10 && n->v == 9))
				change_value_two_nodes(&c, &n, 11);
		}
		c = n;
	}
}

static void	print_str_cmds(int value)
{
	if (value == 1)
		write(1, "sa\n", 3);
	else if (value == 2)
		write(1, "sb\n", 3);
	else if (value == 3)
		write(1, "ss\n", 3);
	else if (value == 4)
		write(1, "pa\n", 3);
	else if (value == 5)
		write(1, "pb\n", 3);
	else if (value == 6)
		write(1, "ra\n", 3);
	else if (value == 7)
		write(1, "rb\n", 3);
	else if (value == 8)
		write(1, "rr\n", 3);
	else if (value == 9)
		write(1, "rra\n", 4);
	else if (value == 10)
		write(1, "rrb\n", 4);
	else if (value == 11)
		write(1, "rrr\n", 4);
}

void	print_num_cmds(t_command *cmd)
{
	t_command	*curr;

	curr = cmd;
	while (curr)
	{
		print_str_cmds(curr->v);
		curr = curr->next;
	}
}

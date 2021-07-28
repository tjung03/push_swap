/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:38:16 by tjung             #+#    #+#             */
/*   Updated: 2021/07/29 03:38:21 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_value_two_nodes(t_command **cur, t_command **nxt, int num)
{
	if (num == 3)
	{
		(*cur)->v = 3;
		(*nxt)->v = -1;
	}
	else if (num == 8)
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

static int	is_null_command(t_command **cmd)
{
	while ((*cmd)->v == -1)
	{
		*cmd = (*cmd)->next;
		if (!(*cmd))
			return (1);
	}
	return (0);
}

static void	change_commands(t_command *c, t_command *n)
{
	if ((c->v == 6 && n->v == 9) || (c->v == 9 && n->v == 6)
		|| (c->v == 7 && n->v == 10) || (c->v == 10 && n->v == 7)
		|| (c->v == 4 && n->v == 5) || (c->v == 5 && n->v == 4)
		|| (c->v == 1 && n->v == 1)
		|| (c->v == 2 && n->v == 2)
		|| (c->v == 3 && n->v == 3)
		|| (c->v == 8 && n->v == 11) || (c->v == 11 && n->v == 8))
		change_values_two_nodes(&c, &n);
	else if ((c->v == 1 && n->v == 2) || (c->v == 2 && n->v == 1))
		change_value_two_nodes(&c, &n, 3);
	else if ((c->v == 6 && n->v == 7) || (c->v == 7 && n->v == 6))
		change_value_two_nodes(&c, &n, 8);
	else if ((c->v == 9 && n->v == 10) || (c->v == 10 && n->v == 9))
		change_value_two_nodes(&c, &n, 11);
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
			if (is_null_command(&n))
				return ;
			change_commands(c, n);
		}
		c = n;
		if (c)
		{
			if (is_null_command(&c))
				return ;
		}
	}
}

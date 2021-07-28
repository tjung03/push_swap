/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:37:36 by tjung             #+#    #+#             */
/*   Updated: 2021/07/29 03:37:39 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

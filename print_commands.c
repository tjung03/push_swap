/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 05:15:06 by marvin            #+#    #+#             */
/*   Updated: 2021/07/28 05:17:22 by marvin           ###   ########.fr       */
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
		print_str_cmds(curr->value);
		curr = curr->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:34:02 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:34:15 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_location(t_list *stack, t_locate *loc)
{
	t_list	*last;

	loc->bottom = stack;
	last = ft_lst_last(stack);
	loc->top = last;
}

int	print_error(int ret, char *str)
{
	if (ret == 1)
		write(1, str, ft_strlen(str));
	return (ret);
}

int	free_sortool(int ret, t_sortool *t)
{
	if (t)
	{
		if (t->pivot)
			free(t->pivot);
		free(t);
	}
	return (ret);
}

int	free_list(int ret, t_global *g)
{
	t_command	*curr;
	t_command	*next;

	ft_lst_clear(g->stack_a);
	ft_lst_clear(g->stack_b);
	curr = g->cmd;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	return (print_error(ret, "Error\n"));
}

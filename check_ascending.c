/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ascending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:41:10 by marvin            #+#    #+#             */
/*   Updated: 2021/07/13 23:24:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ascending(t_global *g)
{
	t_list	*curr;
	int		check_point;
	int		comparison_target;

	curr = g->stack_a;
	while (curr->next)
	{
		check_point = curr->data;
		curr = curr->next;
		comparison_target = curr->data;
		if (check_point < comparison_target)
			return (0);
	}
	return (1);
}

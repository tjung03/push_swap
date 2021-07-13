/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:52:00 by marvin            #+#    #+#             */
/*   Updated: 2021/07/14 05:31:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ascending(t_global *g)
{
	int	size;

	size = ft_lst_size(g->stack_a);
	if (size <= 5)
		sort_not_more_than_five(size, g);
	else if (size <= 100)
		sort_not_more_than_hundred(g);//
	else
		sort_more_than_hundred(g);//
}
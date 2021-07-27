/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:52:00 by marvin            #+#    #+#             */
/*   Updated: 2021/07/28 08:05:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_ascending(t_global *g)
{
	int	lst_size;

	lst_size = ft_lst_size(g->stack_a);
	if (lst_size <= 5)
	{
		if (!sort_not_more_five(g, lst_size))
			return (0);
	}
	else
	{
		if (!sort_more_five(g, lst_size))
			return (0);
	}
	return (1);
}

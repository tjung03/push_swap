/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:34:44 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:34:45 by tjung            ###   ########.fr       */
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

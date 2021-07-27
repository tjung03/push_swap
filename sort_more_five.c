/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:01:15 by marvin            #+#    #+#             */
/*   Updated: 2021/07/28 01:25:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_more_five(t_global *g, int lst_size)
{
	if (!check_a_ascending(g, lst_size))
	{
		if (!sort_a_to_b(g, lst_size))
			return (0);
	}
	return (1);
}

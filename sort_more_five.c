/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:24:46 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:24:48 by tjung            ###   ########.fr       */
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

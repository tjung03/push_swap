/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_hundred.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 05:30:08 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 02:26:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_than_hundred(t_global *g)
{
	int	chunks[12];
	int	size;

	size = ft_lst_size(g->stack_a);
	if (divide_chunks(g, chunks, size, 11))
	{
		
	}
}

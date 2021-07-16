/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:52:00 by marvin            #+#    #+#             */
/*   Updated: 2021/07/17 01:25:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_ascending(t_global *g)
{
	int	*chunks;
	int	size;
	int	success;

	size = ft_lst_size(g->stack_a);
	chunks = NULL;
	if (size <= 5)
		sort_not_more_five(g, size);
	else if (size <= 100)
		success = sort_more_five(g, size, chunks, 5);
	else
		success = sort_more_five(g, size, chunks, 11);
	if (!chunks)
		free(chunks);
	if (!success)
		return (0);
	return (1);
}

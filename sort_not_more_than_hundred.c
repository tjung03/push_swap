/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_not_more_than_hundred.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:01:15 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 02:14:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_corresponding_array(t_global *g, int *arr)
{
	t_list	*curr;
	int		i;
	int		j;
	int		temp;

	curr = g->stack_a;
	i = 0;
	while (curr)
	{
		arr[i++] = curr->data;
		curr = curr->next;
	}
	while (i--)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int			divide_chunks(t_global *g, int *chunks, int zone)
{
	int	*arr;
	int	size;
	int	i;

	size = ft_lst_size(g->stack_a);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	create_corresponding_array(g, arr);
	i = 0;
	while (++i < zone)
		chunks[i] = size * i / zone;
	chunks[0] = arr[0];
	chunks[zone] = arr[size - 1];
	i = 0;
	while (++i < zone)
		chunks[i] = arr[(chunks[i] - 1)];
	return (1);
}

void		sort_not_more_than_hundred(t_global *g)
{
	int	chunks[6];

	divide_chunks(g, chunks, 5);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:52:00 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 02:26:05 by marvin           ###   ########.fr       */
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

int			divide_chunks(t_global *g, int *chunks, int size, int zone)
{
	int	*arr;
	int	i;

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
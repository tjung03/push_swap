/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:19:54 by marvin            #+#    #+#             */
/*   Updated: 2021/07/16 18:49:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	save_lst_to_arr(t_list *stack, int *arr, int *i)
{
	t_list	*curr;

	curr = stack;
	*i = 0;
	while (curr)
	{
		arr[(*i)++] = curr->data;
		curr = curr->next;
	}
}

static void	create_corresponding_array(t_global *g, int *arr)
{
	int		temp;
	int		i;
	int		j;

	save_lst_to_arr(g->stack_a, arr, &i);
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

int	divide_chunks(t_global *g, int *chunks, int size, int zone)
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

int	find_correct_loc_stack_b(t_global *g, int size)
{
	int	*arr;
	int	cnt;
	int	top_a;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (-1);
	save_lst_to_arr(g->stack_b, arr, &i);
	cnt = 0;
	top_a = ((g->loc_a).top)->data;
	i = size;
	while (i-- > 0)
	{
		cnt++;
		if (top_a < arr[i] && top_a > arr[i - 1])
			break ;
	}
	return (cnt);
}

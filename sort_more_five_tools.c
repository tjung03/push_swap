/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:30:44 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:30:46 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_cnt(int ra_cnt, int rb_cnt)
{
	if (ra_cnt <= rb_cnt)
		return (ra_cnt);
	else
		return (rb_cnt);
}

static void	sort_array(int *arr, t_locate *loc, int size)
{
	t_list	*curr;
	int		temp;
	int		i;
	int		j;

	curr = loc->top;
	i = -1;
	while (++i < size)
	{
		arr[i] = curr->data;
		curr = curr->prev;
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

int	*get_pivot(t_locate *loc, int size)
{
	int		*arr;
	int		*pivot;

	arr = (int *)malloc(sizeof(int) * size);
	pivot = (int *)malloc(sizeof(int) * 2);
	if (!arr || !pivot)
		return (NULL);
	sort_array(arr, loc, size);
	pivot[1] = arr[size / 3 * 2];
	pivot[0] = arr[size / 3];
	free(arr);
	return (pivot);
}

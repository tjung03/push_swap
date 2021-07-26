/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:01:15 by marvin            #+#    #+#             */
/*   Updated: 2021/07/27 04:01:47 by marvin           ###   ########.fr       */
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

void	sort_array(int *arr, t_locate *loc, int size)
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

int	sort_b_to_a(t_global *g, int size)
{
	int	*pivot;
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	int	re_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	if (size < 3)
	{
		if (!check_b_descending(g, size))
		{//
			swap_stack(&g->stack_b, &g->loc_b, 'a');
//			print_stacks(g);//
		}//
		while (size--)
		{//
			push_stack_a(g);
//			print_stacks(g);//
		}//
		return (1);
	}
	pivot = get_pivot(&g->loc_b, size);
	if (!pivot)
		return (0);
	/**/
//	printf("b - pivot[0] : %d, pivot[1] : %d\n", pivot[0], pivot[1]);
	/**/
	while (size--)
	{
		if (((g->loc_b).top)->data < pivot[0])// && ft_lst_size(g->stack_b) > 1)
		{
			rotate_stack(&g->stack_b, &g->loc_b, 'b');
//			print_stacks(g);//
			rb_cnt++;
		}
		else
		{
			push_stack_a(g);
//			print_stacks(g);//
			pa_cnt++;
			if (((g->loc_a).top)->data < pivot[1])// && ft_lst_size(g->stack_a) > 1)
			{
				rotate_stack(&g->stack_a, &g->loc_a, 'a');
//				print_stacks(g);//
				ra_cnt++;
			}
		}
	}
	free(pivot);
	if (!sort_a_to_b(g, pa_cnt - ra_cnt))
		return (0);
	re_cnt = find_min_cnt(ra_cnt, rb_cnt);
	while (re_cnt--)
	{//
		reverse_rotate_both_stack(g, 'r');
//		print_stacks(g);//
	}//
	if (ra_cnt <= rb_cnt)
	{
		re_cnt = rb_cnt - ra_cnt;
		while (re_cnt-- > 0)
		{//
			reverse_rotate_stack(&g->stack_b, &g->loc_b, 'b');
//			print_stacks(g);//
		}//
	}
	else
	{
		re_cnt = ra_cnt - rb_cnt;
		while (re_cnt--)
		{//
			reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
//			print_stacks(g);//
		}//
	}
	if (!sort_a_to_b(g, ra_cnt))
		return (0);
	if (!sort_b_to_a(g, rb_cnt))
		return (0);
	return (1);
}

int	sort_a_to_b(t_global *g, int size)
{
	int	*pivot;
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;
	int	re_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	if (size < 3)
	{
		if (!check_a_ascending(g, size))
		{//
			swap_stack(&g->stack_a, &g->loc_a, 'a');
//			print_stacks(g);//
		}//
		return (1);
	}
	pivot = get_pivot(&g->loc_a, size);
	if (!pivot)
		return (0);
	/**/
//	printf("a - pivot[0] : %d, pivot[1] : %d\n", pivot[0], pivot[1]);
	/**/
	while (size--)
	{
		if (((g->loc_a).top)->data >= pivot[1])// && ft_lst_size(g->stack_a) > 1)
		{
			rotate_stack(&g->stack_a, &g->loc_a, 'a');
//			print_stacks(g);//
			ra_cnt++;
		}
		else
		{
			push_stack_b(g);
//			print_stacks(g);//
			pb_cnt++;
			if (((g->loc_b).top)->data >= pivot[0])// && ft_lst_size(g->stack_b) > 1)
			{
				rotate_stack(&g->stack_b, &g->loc_b, 'b');
//				print_stacks(g);//
				rb_cnt++;
			}
		}
	}
	re_cnt = find_min_cnt(ra_cnt, rb_cnt);
	while (re_cnt--)
	{//
		reverse_rotate_both_stack(g, 'r');
//		print_stacks(g);//
	}//
	if (ra_cnt <= rb_cnt)
	{
		re_cnt = rb_cnt - ra_cnt;
		while (re_cnt-- > 0)
		{//
			reverse_rotate_stack(&g->stack_b, &g->loc_b, 'b');
//			print_stacks(g);//
		}//
	}
	else
	{
		re_cnt = ra_cnt - rb_cnt;
		while (re_cnt--)
		{//
			reverse_rotate_stack(&g->stack_a, &g->loc_a, 'a');
//			print_stacks(g);//
		}//
	}
	free(pivot);
	if (!sort_a_to_b(g, ra_cnt))
		return (0);
	if (!sort_b_to_a(g, rb_cnt))
		return (0);
	if (!sort_b_to_a(g, pb_cnt - rb_cnt))
		return (0);
	return (1);
}

int	sort_more_five(t_global *g, int lst_size)
{
//	print_stacks(g);//
	if (!check_a_ascending(g, lst_size))
	{
		if (!sort_a_to_b(g, lst_size))
			return (0);
//		print_stacks(g);//
	}
	return (1);
}

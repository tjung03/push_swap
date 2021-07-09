/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/07/10 04:11:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_global *g)
{
	printf(" start_a(%p), last_a(%p)\n", g->stack_a, ft_lst_last(g->stack_a));
	printf("bottom_a(%p),  top_a(%p)\n", (g->loc_a).bottom, (g->loc_a).top);
	printf("----------\n");
	printf(" start_b(%p), last_b(%p)\n", g->stack_b, ft_lst_last(g->stack_b));
	printf("bottom_a(%p),  top_b(%p)\n", (g->loc_b).bottom, (g->loc_b).top);
	int		size_a = 0;
	int		size_b = 0;
	t_list	*curr_a;
	t_list	*curr_b;

	if (g->stack_a)
	{
		size_a = ft_lst_size(g->stack_a);
		curr_a = ft_lst_last(g->stack_a);
	}
	if (g->stack_b)
	{
		size_b = ft_lst_size(g->stack_b);
		curr_b = ft_lst_last(g->stack_b);
	}
	printf("size_a: %d, size_b: %d\n", size_a, size_b);
	printf("\n");
	int		size;
	if (size_a >= size_b)
		size = size_a;
	else
		size = size_b;
	int		arr_a[size];
	int		arr_b[size];
	ft_memset(arr_a, 0, sizeof(int) * size);
	ft_memset(arr_b, 0, sizeof(int) * size);
	while (size_a--)
	{
		 arr_a[size_a] = curr_a->data;
		 curr_a = curr_a->prev;
	}
	while (size_b--)
	{
		 arr_b[size_b] = curr_b->data;
		 curr_b = curr_b->prev;
	}
	while (size--)
		printf("%10d%10d\n", arr_a[size], arr_b[size]);
	printf("---------------------\n");
	printf("%10c%10c\n\n", 'a', 'b');
}

int	main(int ac, char **av)
{
	t_global	g;

	g.stack_a = NULL;
	g.stack_b = NULL;
	if (ac > 1)
	{
		ft_memset(&g.loc_a, 0, sizeof(t_locate));
		ft_memset(&g.loc_b, 0, sizeof(t_locate));
		if (!get_arguments(av, &g.stack_a))
			return (free_list(1, g.stack_a, g.stack_b));
		stack_location(g.stack_a, &g.loc_a);
		// algorithms

		// test start
		test(&g);
		printf("===start===\n\n");
		swap_stack(&g.loc_a, 'a');
		test(&g);
		push_stack_b(&g);
		test(&g);
		push_stack_b(&g);
		test(&g);
		push_stack_b(&g);
		test(&g);
		push_stack_b(&g);
		test(&g);
		swap_stack(&g.loc_a, 'a');
		test(&g);
		swap_stack(&g.loc_b, 'b');
		test(&g);
		swap_both_stack(&g, 's');
		test(&g);
		push_stack_b(&g);
		push_stack_b(&g);
		push_stack_b(&g);
		push_stack_b(&g);
		push_stack_b(&g);
		push_stack_b(&g);
		push_stack_b(&g);
		test(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		test(&g);
		swap_stack(&g.loc_a, 'a');
		test(&g);
		swap_stack(&g.loc_b, 'b');
		test(&g);
		swap_both_stack(&g, 's');
		test(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		push_stack_a(&g);
		test(&g);
	}
	return (free_list(0, g.stack_a, g.stack_b));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/07/17 01:08:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_global *g)
{
	t_list	*curr;
	int		*arr_a;
	int		*arr_b;
	int		size_a;
	int		size_b;
	int		max_size;

	size_a = ft_lst_size(g->stack_a);
	size_b = ft_lst_size(g->stack_b);
	if (size_a >= size_b)
		max_size = size_a;
	else
		max_size = size_b;
	arr_a = (int *)malloc(sizeof(int) * max_size);
	arr_b = (int *)malloc(sizeof(int) * max_size);
	for (int i = 0; i < max_size; i++)
	{
		arr_a[i] = 0;
		arr_b[i] = 0;
	}
	curr = g->stack_a;
	for (int i = max_size; i > 0; i--)
	{
		if (curr)
		{
			arr_a[i - 1] = curr->data;
			curr = curr->next;
		}
	}
	curr = g->stack_b;
	for (int i = max_size; i > 0; i--)
	{
		if (curr)
		{
			arr_b[i - 1] = curr->data;
			curr = curr->next;
		}
	}
	for (int i = 0; i < max_size; i++)
		printf("%10d%10d\n", arr_a[i], arr_b[i]);
	printf("--------------------\n");
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
		if (!get_arguments(ac, av, &g.stack_a))
			return (free_list(1, g.stack_a, g.stack_b));
		stack_location(g.stack_a, &g.loc_a);
/*
		for(t_list *curr = (g.loc_a).top; curr != NULL; curr = curr->prev)
			printf("%12d", curr->data);
		printf("\n\n");
*/
		if (!sort_ascending(&g))
			return (free_list(1, g.stack_a, g.stack_b));
/*
		for(t_list *curr = (g.loc_a).top; curr != NULL; curr = curr->prev)
			printf("%12d", curr->data);
		printf("\n\n");
*/
	}
	return (free_list(0, g.stack_a, g.stack_b));
}

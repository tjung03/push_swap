/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 19:31:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;
	t_conditions	cdt;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ft_memset(&cdt, 0, sizeof(t_conditions));
		if (!get_arguments(av, &stack_a))
			return (free_list(1, stack_a, stack_b));
		// algorithms

		// test start
		int	i = 1;
		t_list *cur = stack_a;
		while (cur)
		{
			printf("-----\n");
			printf("%d 번, data: %d\n", i, cur->data);
			printf("cur: %p\n", cur);
			printf("next: %p\n", cur->next);
			printf("prev: %p\n", cur->prev);
			i++;
			cur = cur->next;
		}
		int	size = ft_lst_size(stack_a);
		printf("=====\n");
		printf ("count (%d) ?= list size (%d)\n", i - 1, size);//
	}
	return (free_list(0, stack_a, stack_b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:18:59 by marvin            #+#    #+#             */
/*   Updated: 2021/07/10 02:00:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_location(t_list *stack, t_locate *loc)
{
	t_list	*last;

	loc->bottom = stack;
	last = ft_lst_last(stack);
	loc->top = last;
}

int		print_error(int ret, char *str)
{
	if (ret == 1)
		write(1, str, ft_strlen(str));
	return (ret);
}

int		free_list(int ret, t_list *main, t_list *sub)
{
	ft_lst_clear(main);
	ft_lst_clear(sub);
	return (print_error(ret, "Error\n"));
}

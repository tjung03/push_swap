/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:39:03 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 01:36:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_add_back(t_list *lst, int data)
{
	t_list	*new;
	t_list	*last;

	new = ft_lst_new(data);
	if (!new)
		return (0);
	last = ft_lst_last(lst);
	last->next = new;
	new->prev = last;
	return (1);
}

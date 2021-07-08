/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:46:01 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 01:36:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_list *lst)
{
	t_list	*curr;
	t_list	*next;
	int		size;

	size = 0;
	curr = lst;
	while (curr != NULL)
	{
		size++;
		next = curr->next;
		curr = next;
	}
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:35:23 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:35:25 by tjung            ###   ########.fr       */
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

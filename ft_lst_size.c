/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:28:36 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:28:37 by tjung            ###   ########.fr       */
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

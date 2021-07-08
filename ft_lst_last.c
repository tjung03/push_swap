/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:44:31 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 01:36:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_last(t_list *lst)
{
	int		size;

	if (lst == NULL)
		return (NULL);
	size = ft_lst_size(lst);
	while (--size)
		lst = lst->next;
	return (lst);
}

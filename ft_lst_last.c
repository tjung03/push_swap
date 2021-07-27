/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:23:59 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:24:02 by tjung            ###   ########.fr       */
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

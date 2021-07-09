/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 23:40:32 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 01:36:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_clear(t_list *lst)
{
	t_list	*cur;
	t_list	*pre;

	if (!lst)
		return ;
	cur = ft_lst_last(lst);
	while (cur)
	{
		pre = cur->prev;
		free(cur);
		cur = pre;
	}
}


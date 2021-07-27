/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:35:37 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:35:38 by tjung            ###   ########.fr       */
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

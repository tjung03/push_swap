/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:18:59 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 19:19:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(int ret, char *str)
{
	if (ret == 1)
		write(1, str, ft_strlen(str));
	return (ret);
}

int	free_list(int ret, t_list *main, t_list *sub)
{
	ft_lst_clear(main);
	ft_lst_clear(sub);
	return (print_error(ret, "Error\n"));
}

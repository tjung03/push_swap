/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:48:53 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 18:51:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *s)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
		if ((s[i] < 48 || s[i] > 57) && s[i] != ' ' && s[i] != '\t')
		{
			if (s[i] == '-' || s[i] == '+')
			{
				if ((i == 0 && s[1] >= 48 && s[1] <= 57) ||
					(i != 0 && (s[i - 1] == ' ' || s[i - 1] == '\t')
							&& s[i + 1] >= 48 && s[i + 1] <= 57))
				{
					j = 1;
					while ((s[i + ++j] != ' ' || s[i + j] != '\t') && s[i + j])
						if (s[i + j] < 47 || s[i + j] > 57)
							return (0);
					return (1);
				}
			}
			return (0);
		}
	return (1);
}

static int	is_int_range(long long num)
{
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	return (0);
}

int			is_dup(t_list *stack)
{
	t_list	*curr;
	int		num;

	num = ft_lst_last(stack)->data;
	curr = stack;
	while (curr->next)
	{
		if (num == curr->data)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int			is_valid_int(char *s, int *data)
{	
	long long	num;

	if (!is_int(s))
		return (0);
	num = ft_pw_atoi(s);
	if (!is_int_range(num))
		return (0);
	*data = (int)num;
	return (1);
}

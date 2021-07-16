/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:17:16 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 20:43:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_env(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < 48 || av[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	free_split(int ret, char **split)
{
	int	i;

	i = -1;
	if (split)
	{
		while (split[++i])
			free(split[i]);
		free(split);
	}
	return (ret);
}

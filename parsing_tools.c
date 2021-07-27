/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:31:39 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:31:40 by tjung            ###   ########.fr       */
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

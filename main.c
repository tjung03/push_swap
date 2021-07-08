/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:39:46 by marvin            #+#    #+#             */
/*   Updated: 2021/07/09 01:36:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_env(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < 48 && av[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	is_int(char *s)
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

int	is_int_range(long long num)
{
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	return (0);
}

int	is_dup(t_list *stack)
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

int	is_valid_int(char *s, int *data)
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

int	get_arguments(char **av, t_list **stack)
{
	char	**split;
	int		i;
	int		j;
	int		data;

	split = NULL;
	i = 0;
	while (av[++i])
	{
		if (check_env(av[i]))
		{
			split = ft_split(av[i]);
			if (!split)
				return (0);
			j = -1;
			while (split[++j])
			{
				if (!is_valid_int(split[j], &data))
					return (free_split(0, split));
				if (!(*stack))
				{
					*stack = ft_lst_new(data);
					if (!(*stack))
						return (free_split(0, split));
				}
				else
				{
					if (!ft_lst_add_back(*stack, data))
						return (free_split(0, split));
					if (is_dup(*stack))
						return (free_split(0, split));
				}
			}
		}
		else
		{
			if (!is_valid_int(av[i], &data))
				return (0);
			if (!(*stack))
				{
					*stack = ft_lst_new(data);
					if (!(*stack))
						return (0);
				}
			else
			{
				if (!ft_lst_add_back(*stack, data))
					return (0);
				if (is_dup(*stack))
					return (0);
			}
		}
	}
	return (free_split(1, split));
}

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

int	main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;
	t_conditions	cdt;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ft_memset(&cdt, 0, sizeof(t_conditions));
		if (!get_arguments(av, &stack_a))
			return (free_list(1, stack_a, stack_b));
		// algorithms

		// test start
		int	i = 1;
		t_list *cur = stack_a;
		while (cur)
		{
			printf("-----\n");
			printf("%d 번, data: %d\n", i, cur->data);
			printf("cur: %p\n", cur);
			printf("next: %p\n", cur->next);
			printf("prev: %p\n", cur->prev);
			i++;
			cur = cur->next;
		}
		int	size = ft_lst_size(stack_a);
		printf("=====\n");
		printf ("count (%d) ?= list size (%d)\n", i - 1, size);//
	}
	return (free_list(0, stack_a, stack_b));
}

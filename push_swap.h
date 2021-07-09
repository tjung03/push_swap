/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:35:02 by tjung             #+#    #+#             */
/*   Updated: 2021/07/09 19:18:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // test

typedef struct s_list {
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_conditions {
	struct s_list	*a_top;
	struct s_list	*a_bottom;
	struct s_list	*b_top;
	struct s_list	*b_bottom;
}	t_conditions;

/*
 *			ft_functions
 */
int 	    ft_lst_add_back(t_list *lst, int data);
void	    ft_lst_clear(t_list *lst);
t_list	    *ft_lst_last(t_list *lst);
t_list	    *ft_lst_new(int value);
int	        ft_lst_size(t_list *lst);
void    	*ft_memset(void *b, int c, size_t len);
long long   ft_pw_atoi(char *s);
char	    **ft_split(char const *s);
int	    	ft_strlen(char *s);

/*
 *			argument_valid.c
 */
int			is_valid_int(char *s, int *data);
int			is_dup(t_list *stack);

/*
 *			parsing.c
 */
int			get_arguments(char **av, t_list **stack);

/*
 *			parsing_tools.c
 */
int			check_env(char *av);
int			free_split(int ret, char **split);

/*
 *			tools.c
 */
int			print_error(int ret, char *str);
int			free_list(int ret, t_list *main, t_list *sub);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:35:02 by tjung             #+#    #+#             */
/*   Updated: 2021/07/10 07:15:26 by marvin           ###   ########.fr       */
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

typedef struct s_locate {
	struct s_list	*top;
	struct s_list	*bottom;
}	t_locate;

typedef struct	s_global {
	struct s_list	*stack_a;
	struct s_list	*stack_b;
	struct s_locate	loc_a;
	struct s_locate	loc_b;
}	t_global;


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
void		stack_location(t_list *stack, t_locate *loc);
int			print_error(int ret, char *str);
int			free_list(int ret, t_list *main, t_list *sub);

/*
 *			func_swap.c
 */
void    	swap_stack(t_locate *loc, char stack);
void    	swap_both_stack(t_global *g, char stack);

/*
 *			func_push.c
 */
void		push_stack_a(t_global *g);
void		push_stack_b(t_global *g);


/*
 *			func_rotate.c
 */
void		rotate_stack(t_list **stack, t_locate *loc, char kind);
void		rotate_both_stack(t_global *g, char kind);

/*
 *			func_reverse_rotate.c
 */
void		reverse_rotate_stack(t_list **stack, t_locate *loc, char kind);
void		reverse_rotate_both_stack(t_global *g, char kind);

#endif
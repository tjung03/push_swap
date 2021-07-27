/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:34:28 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:34:32 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>//

typedef struct s_sortool {
	int	*pivot;
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;
	int	pa_cnt;
	int	re_cnt;
}	t_sortool;

typedef struct s_command {
	int					v;
	struct s_command	*next;
}	t_command;

typedef struct s_list {
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_locate {
	struct s_list	*top;
	struct s_list	*bottom;
}	t_locate;

typedef struct s_global {
	struct s_list		*stack_a;
	struct s_list		*stack_b;
	struct s_locate		loc_a;
	struct s_locate		loc_b;
	struct s_command	*cmd;
}	t_global;

/*
 *			ft_functions
 */
int			ft_lst_add_back(t_list *lst, int data);
void		ft_lst_clear(t_list *lst);
t_list		*ft_lst_last(t_list *lst);
t_list		*ft_lst_new(int value);
int			ft_lst_size(t_list *lst);
void		*ft_memset(void *b, int c, size_t len);
long long	ft_pw_atoi(char *s);
char		**ft_split(char const *s);
int			ft_strlen(char *s);

/*
 *			parsing.c
 */
int			get_arguments(int ac, char **av, t_list **stack);

/*
 *			parsing_tools.c
 */
int			check_env(char *av);
int			free_split(int ret, char **split);

/*
 *			argument_valid.c
 */
int			is_valid_int(char *s, int *data);
int			is_dup(t_list *stack);

/*
 *			tools.c
 */
void		stack_location(t_list *stack, t_locate *loc);
int			print_error(int ret, char *str);
int			free_sortool(int ret, t_sortool *t);
int			free_list(int ret, t_global *g);

/*
 *			print_commands.c
 */
void		delete_unnecessary_commands(t_command **cmd);
void		print_num_cmds(t_command *cmd);

/*
 *			command_tools.c
 */
int			execute_cmds(t_global *g, int num);

/*
 *			func_swap.c
 */
int			swap_stack(t_list **stack, t_locate *loc, char kind);
int			swap_both_stack(t_global *g, char kind);

/*
 *			func_push.c
 */
int			push_stack_a(t_global *g);
int			push_stack_b(t_global *g);

/*
 *			func_rotate.c
 */
int			rotate_stack(t_list **stack, t_locate *loc, char kind);
int			rotate_both_stack(t_global *g, char kind);

/*
 *			func_reverse_rotate.c
 */
int			reverse_rotate_stack(t_list **stack, t_locate *loc, char kind);
int			reverse_rotate_both_stack(t_global *g, char kind);

/*
 *			check_sorting.c
 */
int			check_a_ascending(t_global *g, int size);
int			check_b_descending(t_global *g, int size);

/*
 *			sort_ascending.c
 */
int			sort_ascending(t_global *g);

/*
 *			sort_not_more_five.c
 */
int			sort_not_more_five(t_global *g, int size);

/*
 *			sort_not_more_five_details.c
 */
int			top_isnt_min_in_three(t_global *g);
int			raise_one_to_top_in_five(t_global *g, int idx);

/*
 *			sort_not_more_five_tools.c
 */
int			what_min_idx(t_locate *loc);
int			what_max_idx(t_locate *loc);
int			top_is_min(t_global *g);
int			top_is_max(t_global *g);

/*
 *			sort_more_five.c
 */
int			sort_more_five(t_global *g, int lst_size);

/*
 *			sort_more_five_a_to_b.c
 */
int			sort_a_to_b(t_global *g, int size);

/*
 *			sort_more_five_b_to_a.c
 */
int			sort_b_to_a(t_global *g, int size);

/*
 *			sort_more_five_tools.c
 */
int			*get_pivot(t_locate *loc, int size);
int			find_min_cnt(int ra_cnt, int rb_cnt);

#endif

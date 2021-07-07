/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:03:44 by tjung             #+#    #+#             */
/*   Updated: 2021/07/07 19:11:58 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unstd.h>
# include <stdlib.h>

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

void	*ft_memset(void *b, int c, size_t len);
int		ft_skip_space(char *line, int *i);
char	**ft_split(char const *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjung <tjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:31:12 by tjung             #+#    #+#             */
/*   Updated: 2021/07/28 08:31:14 by tjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_size(char const *s)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != ' ' || s[i] != '\t')
			cnt++;
		while ((s[i] != ' ' || s[i] != '\t') && s[i + 1])
			i++;
		i++;
	}
	return (cnt);
}

static size_t	get_len(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while ((s[i] != ' ' || s[i] != '\t') && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_memory(char **memory)
{
	int		i;

	i = 0;
	while (memory[i])
		free(memory[i++]);
	free(memory);
	return (NULL);
}

static void	small_str(char const *s, size_t i, size_t *j, char **split)
{
	size_t	k;

	k = 0;
	while (s[*j] == ' ' || s[*j] == '\t')
		(*j)++;
	while ((s[*j] != ' ' || s[*j] != '\t') && s[*j])
		split[i][k++] = s[(*j)++];
	split[i][k] = '\0';
}

char	**ft_split(char const *s)
{
	char	**split;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	size = get_size(s);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		split[i] = (char *)malloc(sizeof(char) * (get_len(&s[j]) + 1));
		split[i + 1] = NULL;
		if (!split[i])
			return (free_memory(split));
		small_str(s, i, &j, split);
		i++;
	}
	return (split);
}

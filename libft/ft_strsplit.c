/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:32:52 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/02 17:46:22 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		**clean_split(char **split, int i)
{
	int				loc;

	loc = 0;
	while (loc < i)
	{
		free(split[loc]);
		loc++;
	}
	split[0] = NULL;
	return (split);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**split;
	int				i;

	i = 0;
	split = (void*)0;
	if (s)
	{
		split = (char**)malloc(sizeof(char*) * (ft_my_count_c_words(s, c) + 1));
		if (!split)
			return ((void*)0);
		while (*s)
		{
			while (*s && *s == c)
				s++;
			if (*s && *s != c && (split[i] = ft_my_malloc_c_word(s, c)))
				i++;
			else if (!split[i - 1])
				return (split = clean_split(split, i));
			while (*s && *s != c)
				s++;
		}
		split[i] = (void*)0;
	}
	return (split);
}

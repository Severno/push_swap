/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:05:50 by sapril            #+#    #+#             */
/*   Updated: 2019/10/23 13:21:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

static int			c_wor(const char *str, char c)
{
	int word;
	int i;

	word = 0;
	i = 0;
	if (str[i] != c && str[i])
	{
		i++;
		word++;
	}
	while (str[i])
	{
		while (str[i] == c)
		{
			i++;
			if (str[i] != c && str[i])
				word++;
		}
		i++;
	}
	return (word);
}

static int			get_len(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static void			*free_words(char **words)
{
	int i;

	i = 0;
	while (words[i])
	{
		free(words[i++]);
		words[i] = NULL;
	}
	free(words);
	words = NULL;
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**s_w;
	int		j;
	int		k;

	if (!s || !(s_w = (char **)ft_memalloc(sizeof(char *) * (c_wor(s, c)) + 1)))
		return (NULL);
	j = 0;
	k = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(s_w[j] = (char *)ft_memalloc(get_len(s, c) + 1)))
				return (free_words(s_w));
			while (*s != c && *s)
				s_w[j][k++] = *s++;
			s_w[j++][k] = '\0';
			k = 0;
		}
	}
	s_w[j] = NULL;
	return (s_w);
}

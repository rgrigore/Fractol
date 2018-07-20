/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:07:11 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/12 18:37:44 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	w;
	size_t	i;

	i = -1;
	w = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
	}
	return (w);
}

static size_t	letter_count(char const *s, char c, size_t i)
{
	size_t	count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static size_t	skip(char const *s, char c, size_t i)
{
	while (s[i] == c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**tmp;
	size_t	w;
	size_t	l;
	size_t	j;

	if (!s)
		return (NULL);
	j = word_count(s, c);
	if (!(tmp = (char**)malloc((j + 1) * sizeof(char*))))
		return (NULL);
	tmp[j] = 0;
	w = 0;
	i = 0;
	while (w < j)
	{
		i = skip(s, c, i);
		l = letter_count(s, c, i);
		if (s[i])
			if ((tmp[w] = (char*)ft_memalloc((l + 1) * sizeof(char))))
				ft_strncpy(tmp[w++], s + i, l);
		i = i + l;
	}
	return (tmp);
}

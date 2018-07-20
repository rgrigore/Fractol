/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:22:35 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/12 11:10:38 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(const char *s)
{
	int	i;

	i = 0;
	while (ft_isblanks(s[i]))
		i++;
	return (i);
}

static int	rtrim(const char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (ft_isblanks(s[i]))
		i--;
	return (i);
}

char		*ft_strtrim(const char *s)
{
	char	*new;
	int		size;
	int		srt;
	int		end;

	if (s)
	{
		srt = trim(s);
		end = rtrim(s);
		if ((size = ++end - srt) < 1)
			size = 1;
		if ((new = ft_strnew(size)))
		{
			size = 0;
			while (srt < end)
				new[size++] = s[srt++];
			return (new);
		}
	}
	return (NULL);
}

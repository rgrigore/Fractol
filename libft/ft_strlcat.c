/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:43:03 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/08 16:49:48 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		p;

	p = 0;
	i = -1;
	while (size > 0 && p == 0 && ++i < size)
		if (dst[i] == '\0')
			p = 1;
	j = ft_strlen(dst);
	k = ft_strlen(src);
	if (p == 0)
		return (size + k);
	else
	{
		i = -1;
		while (src[++i] != '\0' && i < size - j - 1)
			dst[j + i] = src[i];
		dst[j + i] = '\0';
	}
	return (j + k);
}

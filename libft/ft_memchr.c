/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:37:15 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/07 07:32:46 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	t;
	unsigned char	*tmp;

	tmp = (unsigned char*)s;
	t = (unsigned char)c;
	i = 0;
	while (i < n)
		if (tmp[i++] == t)
			return ((void*)s + i - 1);
	return (NULL);
}

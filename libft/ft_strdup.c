/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:01:56 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/07 07:49:12 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (s1[i])
		i++;
	if ((tmp = (char*)ft_memalloc((i + 1) * sizeof(char))))
	{
		while ((long long)i >= 0)
		{
			tmp[i] = s1[i];
			i--;
		}
		return (tmp);
	}
	return (NULL);
}

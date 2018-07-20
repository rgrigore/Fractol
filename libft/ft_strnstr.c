/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:56:18 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/09 10:57:34 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = -1;
	j = 0;
	if (little[j] == '\0')
		return ((char*)big);
	while (big[++i] && i < len)
		if (big[i] == little[j])
		{
			k = i - 1;
			while (big[++k] == little[j] && k < len)
			{
				if (little[j + 1] == '\0')
					return ((char*)big + i);
				j++;
			}
			j = 0;
		}
	return (NULL);
}

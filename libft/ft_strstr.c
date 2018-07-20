/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:27:45 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/14 11:41:17 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	s;

	i = -1;
	j = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[++i])
		if (big[i] == little[j])
		{
			s = i - 1;
			while (big[++s] == little[j])
			{
				if (little[j + 1] == '\0')
					return ((char*)big + i);
				j++;
			}
			j = 0;
		}
	return (NULL);
}

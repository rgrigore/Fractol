/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:45:16 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/09 10:44:17 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tmp;
	size_t		i;

	if (s)
	{
		if ((tmp = (char*)ft_memalloc((len + 1) * sizeof(char))))
		{
			i = -1;
			while (++i < len)
				tmp[i] = s[start++];
			return (tmp);
		}
	}
	return (NULL);
}

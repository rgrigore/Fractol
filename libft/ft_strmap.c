/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:16:40 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/09 10:38:54 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		if ((str = (char*)ft_memalloc((i + 1) * sizeof(char))))
		{
			while (--i >= 0)
				str[i] = f(s[i]);
			return (str);
		}
	}
	return (NULL);
}

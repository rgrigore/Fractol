/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 07:05:56 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/07 07:21:56 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = -1;
	while (++i <= ft_strlen(s))
		if (s[i] == (char)c)
			return ((char*)s + i);
	return (NULL);
}

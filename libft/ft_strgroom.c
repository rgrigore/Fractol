/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgroom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:16:19 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/14 11:39:41 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strgroom(void *str, int c)
{
	size_t			i;
	unsigned char	*tmp;

	if (str)
	{
		tmp = (unsigned char*)str;
		i = -1;
		while (tmp[++i])
		{
			while (tmp[i] == (char)c &&
					(i == 0 || tmp[i] == tmp[i + 1] || tmp[i + 1] == '\0'))
				ft_strcpy((char*)(tmp + i), (char*)(tmp + i + 1));
		}
		return (str);
	}
	return (NULL);
}

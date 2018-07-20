/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:17:53 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/11 11:17:56 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrcpy(char **dst, char *src, char c)
{
	char	*tmp;
	int		i;
	int		count;
	int		pos;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	if (!(tmp = ft_strnew(1)))
		return (0);
	count = -1;
	while (++count < i && src[count])
	{
		tmp[0] = src[count];
		if (!(*dst = ft_strjoin(*dst, tmp)))
			return (0);
	}
	free(tmp);
	return (pos);
}

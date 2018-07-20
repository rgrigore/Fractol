/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:54:57 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/11 19:36:16 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n;
	int		m;
	int		i;
	int		j;
	char	*tmp;

	if (s1 && s2)
	{
		n = 0;
		while (s1[n])
			n++;
		m = 0;
		while (s2[m])
			m++;
		if (!(tmp = (char*)ft_memalloc((n + m + 1) * sizeof(char))))
			return (NULL);
		i = -1;
		while (s1[++i])
			tmp[i] = s1[i];
		j = -1;
		while (s2[++j])
			tmp[i++] = s2[j];
		return (tmp);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:00:27 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/14 11:39:18 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] == s2[i] && s1[i] && s2[i])
			i++;
		if (s1[i] == s2[i])
			return (1);
	}
	return (0);
}

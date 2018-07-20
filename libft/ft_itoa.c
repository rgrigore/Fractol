/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:46:41 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/08 19:34:43 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sad(char *p, int n, int s, int j)
{
	int c;

	c = n;
	while (c)
	{
		p[--j] = (c % 10) * s + '0';
		c /= 10;
	}
	if (n == 0)
	{
		p[--j] = '0';
	}
}

static char	*halp(int n, int s, int j)
{
	char	*p;

	if (n < 0)
	{
		s = -1;
		if (!(p = (char*)malloc((j + 1 - ((s - 1) / 2)) * sizeof(char))))
			return (NULL);
		p[j + 1] = '\0';
		j++;
		p[0] = '-';
	}
	else
	{
		s = 1;
		if (!(p = (char*)malloc((j + 1 - ((s - 1) / 2)) * sizeof(char))))
			return (NULL);
		p[j] = '\0';
	}
	sad(p, n, s, j);
	return (p);
}

char		*ft_itoa(int n)
{
	int		j;
	char	*p;
	int		c;
	int		s;

	j = 0;
	c = n;
	while (c)
	{
		j++;
		c /= 10;
	}
	if (n == 0)
		j = 1;
	s = 0;
	if (!(p = (halp(n, s, j))))
		return (NULL);
	return (p);
}

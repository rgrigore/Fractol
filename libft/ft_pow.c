/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:47:44 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/14 16:05:03 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_pow(long long nr, size_t p)
{
	long long	c;

	c = nr;
	if (p == 0)
		return (1);
	while (--p > 0)
		nr *= c;
	return (nr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:23:29 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/29 14:26:04 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			sign;
	long long	nr;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	nr = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		if (nr > 922337203685477580 && sign == 1)
			return (-1);
		if (nr < -922337203685477580 && sign == -1)
			return (0);
		nr = nr * 10 + sign * (*str++ - '0');
		if (sign == 1 && nr < 0)
			return (-1);
		if (sign == -1 && nr > 0)
			return (0);
	}
	return (nr);
}

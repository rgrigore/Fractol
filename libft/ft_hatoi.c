/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:04:11 by rgrigore          #+#    #+#             */
/*   Updated: 2018/01/31 19:04:12 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hatoi(char *str)
{
	int			sign;
	long long	nr;
	int			i;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	nr = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	i = 1;
	while (str[++i] != '\0' && ft_strchr(HEX, str[i]))
	{
		if (ft_isdigit(str[i]))
			nr = (nr << 4) + ((str[i] - '0') | 0);
		else
		{
			str[i] = ft_toupper(str[i]);
			nr = (nr << 4) + ((str[i] - 55) | 0);
		}
	}
	return (nr * sign);
}

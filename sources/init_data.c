/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:57:32 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:57:33 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_valid_input(t_data *data)
{
	data->valid_input = (char**)malloc(sizeof(char*) * (5 + 1));
	data->valid_input[5] = NULL;
	data->valid_input[0] = ft_strdup("Mandelbrot");
	data->valid_input[1] = ft_strdup("Julia");
	data->valid_input[2] = ft_strdup("BurningShip");
	data->valid_input[3] = ft_strdup("Mandelbar");
	data->valid_input[4] = ft_strdup("Flowerbrot");
}

void		init_data(t_data *data)
{
	set_valid_input(data);
	data->win_count = 0;
	data->to_render = NULL;
}

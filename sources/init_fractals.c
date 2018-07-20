/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:57:44 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:57:47 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fdata(t_fract_data *f_data)
{
	f_data->zoom = 0.3;
	f_data->offset_x = 0;
	f_data->offset_y = 0;
	f_data->j_toggle = 0;
	f_data->j_real = 0;
	f_data->j_imag = 0;
	f_data->color = (int**)malloc(sizeof(int*) * 5);
	f_data->color[4] = NULL;
	f_data->color[0] = (int*)malloc(sizeof(int) * 3);
	f_data->color[0][0] = 0x0000005f;
	f_data->color[0][1] = 0x00ffffff;
	f_data->color[0][2] = 0x00BF7818;
	f_data->color[1] = (int*)malloc(sizeof(int) * 3);
	f_data->color[1][0] = 0x00000000;
	f_data->color[1][1] = 0x00ffffff;
	f_data->color[1][2] = 0x0000ff00;
	f_data->color[2] = (int*)malloc(sizeof(int) * 3);
	f_data->color[2][0] = 0x007A00E5;
	f_data->color[2][1] = 0x00E500DC;
	f_data->color[2][2] = 0x00ffffff;
	f_data->color[3] = (int*)malloc(sizeof(int) * 3);
	f_data->color[3][0] = 0x0091481D;
	f_data->color[3][1] = 0x001EA968;
	f_data->color[3][2] = 0x00000000;
}

void		init_fractals(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->win_count)
	{
		init_fdata(&data->window[i].f_data);
		data->window[i].active_color = 0;
		data->window[i].iter = START_ITER;
		data->window[i].lpt = W_HEIGHT / T_COUNT;
		data->window[i].building = 0;
		data->window[i].thread = (t_thread*)malloc(sizeof(t_thread) * T_COUNT);
		j = -1;
		while (++j < T_COUNT)
		{
			data->window[i].thread[j].window = &data->window[i];
			data->window[i].thread[j].start = j * data->window[i].lpt;
		}
		build_fractal(&data->window[i]);
	}
}

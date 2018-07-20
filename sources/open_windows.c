/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:58:04 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:58:05 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	open_windows(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->win_count)
	{
		data->window[i].win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT,
								data->window[i].name);
		MLX_PITW(data->mlx, data->window[i].win,
					data->window[i].image.value, 0, 0);
	}
}

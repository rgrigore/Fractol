/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:58:25 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:58:26 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	triggers(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->win_count)
	{
		mlx_hook(data->window[i].win, 4, 0, event_mouse_down, &data->window[i]);
		mlx_hook(data->window[i].win, 6, 0, event_mouse_move, &data->window[i]);
		mlx_hook(data->window[i].win, 2, 0, event_keyboard, &data->window[i]);
	}
}

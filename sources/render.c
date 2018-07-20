/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:58:10 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:58:11 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		render(t_data *data)
{
	if (data->to_render)
	{
		MLX_PITW(data->mlx, data->to_render->win,
					data->to_render->image.value, 0, 0);
		data->to_render->building = 0;
	}
	return (0);
}

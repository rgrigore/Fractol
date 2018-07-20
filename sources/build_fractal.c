/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:56:56 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:56:58 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	build_fractal(t_window *window)
{
	int	i;

	window->building = 1;
	i = -1;
	while (++i < T_COUNT)
		pthread_create(&window->thread[i].t_id, NULL, window->build,
														&window->thread[i]);
	while (--i >= 0)
		pthread_join(window->thread[i].t_id, NULL);
}

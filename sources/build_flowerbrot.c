/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_flowerbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:56:50 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:56:51 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate(t_thread *thr, int x, int y)
{
	t_complex	p;
	t_complex	n;
	double		t;
	int			i;

	p.r = (x - W_WIDTH / 2) / (thr->window->f_data.zoom * W_WIDTH) +
												thr->window->f_data.offset_x;
	p.i = (y - W_HEIGHT / 2) / (thr->window->f_data.zoom * W_HEIGHT) +
												thr->window->f_data.offset_y;
	n.r = 0;
	n.i = 0;
	i = -1;
	while (++i < thr->window->iter && pow(n.r, 6) + pow(n.i, 6) < 4)
	{
		t = n.r;
		n.r = pow(n.r, 6) - (15 * pow(n.r, 4) * pow(n.i, 2)) +
						(15 * pow(n.r, 2) * pow(n.i, 4)) - pow(n.i, 6) + p.i;
		n.i = (6 * pow(t, 5) * n.i - 20 * pow(t, 3) * pow(n.i, 3) +
												6 * t * pow(n.i, 5)) + p.r;
	}
	thr->window->image.pixel[x + y * W_WIDTH] =
		set_color(thr->window->f_data.color[thr->window->active_color],
			(float)i / thr->window->iter + !(i < thr->window->iter));
}

void		*build_flowerbrot(void *thread)
{
	t_thread	*thr;
	int			y;
	int			x;

	thr = (t_thread*)thread;
	y = thr->start;
	while (y < W_HEIGHT && y < thr->start + thr->window->lpt)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			calculate(thr, x, y);
		}
		y++;
	}
	return (NULL);
}

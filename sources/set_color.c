/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:58:16 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:58:18 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(unsigned int start, unsigned int end, float position)
{
	int		current_color;
	t_argb	c1;
	t_argb	c2;
	t_argb	c;

	if (position > 1)
		position = 1;
	c1.r = start >> 16;
	c1.g = start >> 8 & 0xff;
	c1.b = start & 0xff;
	c2.r = end >> 16;
	c2.g = end >> 8 & 0xff;
	c2.b = end & 0xff;
	c.r = c1.r + position * (c2.r - c1.r);
	c.g = c1.g + position * (c2.g - c1.g);
	c.b = c1.b + position * (c2.b - c1.b);
	current_color = (1 << 24) + (c.r << 16) + (c.g << 8) + (c.b | 0);
	return (current_color);
}

int			set_color(int *color, float pos)
{
	if (pos < 0.1)
		return (get_color(color[0], color[1], (pos - 0.0) / 0.1));
	else if (pos < 0.2)
		return (get_color(color[1], color[2], (pos - 0.1) / 0.1));
	else if (pos < 0.3)
		return (get_color(color[2], color[0], (pos - 0.2) / 0.1));
	else if (pos < 0.4)
		return (get_color(color[0], color[1], (pos - 0.3) / 0.1));
	else if (pos < 0.5)
		return (get_color(color[1], color[2], (pos - 0.4) / 0.1));
	else if (pos < 0.6)
		return (get_color(color[2], color[0], (pos - 0.5) / 0.1));
	else if (pos < 0.7)
		return (get_color(color[0], color[1], (pos - 0.6) / 0.1));
	else if (pos < 0.8)
		return (get_color(color[1], color[2], (pos - 0.7) / 0.1));
	else if (pos < 0.9)
		return (get_color(color[2], color[0], (pos - 0.8) / 0.1));
	else if (pos <= 1)
		return (get_color(color[0], color[1], (pos - 0.9) / 0.1));
	return (0);
}

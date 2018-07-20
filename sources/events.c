/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:57:24 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:57:26 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		event_mouse_down(int keycode, int mouse_x, int mouse_y, t_window *win)
{
	double	zoom;
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	if ((keycode == 4 || keycode == 5) && !win->building)
	{
		zoom = win->f_data.zoom;
		if (keycode == 4)
			win->f_data.zoom *= 1.07213535211;
		else if (keycode == 5)
			win->f_data.zoom /= 1.07213535211;
		old_x = mouse_x - (W_WIDTH / 2);
		old_y = mouse_y - (W_HEIGHT / 2);
		new_x = old_x * (win->f_data.zoom / zoom);
		new_y = old_y * (win->f_data.zoom / zoom);
		win->f_data.offset_x += ((new_x - old_x)) / W_WIDTH / win->f_data.zoom;
		win->f_data.offset_y += ((new_y - old_y)) / W_HEIGHT / win->f_data.zoom;
		build_fractal(win);
	}
	*win->to_render = win;
	return (0);
}

int		event_mouse_move(int mouse_x, int mouse_y, t_window *window)
{
	if (window->f_data.j_toggle && !window->building)
	{
		if (mouse_x <= W_WIDTH / 2)
			window->f_data.j_real = -0.2 * ((W_WIDTH / 2 - (double)mouse_x) /
																W_WIDTH / 2);
		else if (mouse_x > W_WIDTH / 2)
			window->f_data.j_real = 0.2 * (((double)mouse_x - W_WIDTH / 2) /
																W_WIDTH / 2);
		if (mouse_y <= W_HEIGHT / 2)
			window->f_data.j_imag = 0.2 * ((W_HEIGHT / 2 - (double)mouse_y) /
																W_HEIGHT / 2);
		else if (mouse_y > W_HEIGHT / 2)
			window->f_data.j_imag = -0.2 * (((double)mouse_y - W_HEIGHT / 2) /
																W_HEIGHT / 2);
		build_fractal(window);
	}
	*window->to_render = window;
	return (0);
}

int		event_keyboard(int keycode, t_window *window)
{
	if (!window->building)
	{
		if (keycode == KEY_ESCAPE)
			exit(0);
		else if (keycode == KEY_C)
			window->active_color = (window->f_data.color[window->active_color +
				1]) ? window->active_color + 1 : 0;
		else if (keycode == NUM_PLUS || keycode == NUM_MINUS)
			window->iter += (keycode == NUM_PLUS) ? 1 : -1;
		else if (keycode == NUM_8 || keycode == ARROW_UP || keycode == KEY_W)
			window->f_data.offset_y -= 0.01 / window->f_data.zoom;
		else if (keycode == NUM_2 || keycode == ARROW_DOWN || keycode == KEY_S)
			window->f_data.offset_y += 0.01 / window->f_data.zoom;
		else if (keycode == NUM_4 || keycode == ARROW_LEFT || keycode == KEY_A)
			window->f_data.offset_x -= 0.01 / window->f_data.zoom;
		else if (keycode == NUM_6 || keycode == ARROW_RIGHT || keycode == KEY_D)
			window->f_data.offset_x += 0.01 / window->f_data.zoom;
		else if (keycode == KEY_SPACE)
			if (!ft_strcmp(window->name, "Julia"))
				window->f_data.j_toggle = (window->f_data.j_toggle == 0);
		build_fractal(window);
	}
	*window->to_render = window;
	return (0);
}

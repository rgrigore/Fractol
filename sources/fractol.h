/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:56:12 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:56:16 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <pthread.h>
# include <libft.h>
# include <stdlib.h>
# include <math.h>
# include "mlx_keys.h"

# include <stdio.h>

# define W_WIDTH 800
# define W_HEIGHT 600

# define START_ITER 400

# define T_COUNT 20

# define MLX_PITW mlx_put_image_to_window

typedef struct			s_argb
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}						t_argb;

typedef struct			s_complex
{
	double	r;
	double	i;
}						t_complex;

typedef struct			s_img_data
{
	void	*value;
	int		*pixel;
	int		l_size;
	int		bpp;
	int		endi;
}						t_img_data;

typedef	struct s_window	t_window;

typedef struct			s_thread
{
	pthread_t	t_id;
	int			start;
	t_window	*window;
}						t_thread;

typedef struct			s_fract_data
{
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		j_real;
	double		j_imag;
	int			j_toggle;
	int			**color;
}						t_fract_data;

struct					s_window
{
	int				id;
	void			*win;
	char			*name;
	void			*(*build)(void*);
	t_fract_data	f_data;
	t_img_data		image;
	int				active_color;
	struct s_window	**to_render;
	t_thread		*thread;
	int				lpt;
	int				building;
	int				iter;
};

typedef struct			s_data
{
	void		*mlx;
	t_window	*window;
	t_window	*to_render;
	int			win_count;
	char		**valid_input;
}						t_data;

void					init_data(t_data *data);
void					manage_input(t_data *data, int ac, char **av);
void					open_windows(t_data *data);

void					init_fractals(t_data *data);
void					build_fractal(t_window *window);
void					*build_mandelbrot(void *thread);
void					*build_mandelbar(void *thread);
void					*build_julia(void *thread);
void					*build_burningship(void *thread);
void					*build_flowerbrot(void *thread);
int						set_color(int *color, float pos);

void					triggers(t_data *data);
int						event_mouse_down(int k, int m_x, int m_y, t_window *w);
int						event_mouse_move(int m_x, int m_y, t_window *win);
int						event_keyboard(int keycode, t_window *win);

int						render(t_data *data);

#endif

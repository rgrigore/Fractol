/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:57:58 by rgrigore          #+#    #+#             */
/*   Updated: 2018/03/07 14:58:00 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_valid(char **valid_input)
{
	int	i;

	ft_putendl("Valid fractals:");
	i = -1;
	while (valid_input[++i])
	{
		ft_putendl(valid_input[i]);
	}
	exit(0);
}

static void	init_img(void *mlx, t_img_data *img, int color)
{
	int			i;

	img->bpp = 32;
	img->endi = 0;
	img->value = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	img->l_size = W_WIDTH * img->bpp;
	img->pixel = (int*)mlx_get_data_addr(img->value, &img->bpp,
									&img->l_size, &img->endi);
	i = -1;
	while (++i < W_WIDTH * W_HEIGHT)
		*(img->pixel + i) = color;
}

static void	set_windows(t_data *data, int *input)
{
	int	i;

	data->window = (t_window*)malloc(sizeof(t_window) * data->win_count);
	i = -1;
	while (++i < data->win_count)
	{
		data->window[i].name = data->valid_input[input[i] - 1];
		data->window[i].id = i;
		data->window[i].to_render = (t_window**)malloc(sizeof(t_window*));
		data->window[i].to_render = &data->to_render;
		init_img(data->mlx, &data->window[i].image, 0X00000000);
		if (input[i] - 1 == 0)
			data->window[i].build = build_mandelbrot;
		else if (input[i] - 1 == 1)
			data->window[i].build = build_julia;
		else if (input[i] - 1 == 2)
			data->window[i].build = build_burningship;
		else if (input[i] - 1 == 3)
			data->window[i].build = build_mandelbar;
		else if (input[i] - 1 == 4)
			data->window[i].build = build_flowerbrot;
	}
}

void		manage_input(t_data *data, int ac, char **av)
{
	int	i;
	int	j;
	int	*input;

	input = (int*)ft_memalloc(sizeof(int) * 1000);
	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (data->valid_input[++j])
			if (!ft_strcmp(av[i], data->valid_input[j]))
			{
				input[data->win_count++] = j + 1;
				break ;
			}
		if (!data->valid_input[j])
		{
			ft_putstr(av[i]);
			ft_putendl(": Invalid input!");
		}
	}
	if (data->win_count == 0)
		print_valid(data->valid_input);
	set_windows(data, input);
	free(input);
}

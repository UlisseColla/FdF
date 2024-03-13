/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:21:08 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/13 17:20:39 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_window(t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			ft_pixel_put(&(data->img), i, j, 0x000000);
			i++;
		}
		j++;
	}
}

void	reset_parameters(t_vars_mlx *data, int flag, int i, int j)
{
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			if (flag == 1)
			{
				data->map[j][i].screen_x = data->map[j][i].x;
				data->map[j][i].screen_y = data->map[j][i].y;
			}
			else
			{
				data->map[j][i].x = data->map[j][i].reset_x;
				data->map[j][i].y = data->map[j][i].reset_y;
				data->map[j][i].screen_x = data->map[j][i].reset_s_x;
				data->map[j][i].screen_y = data->map[j][i].reset_s_y;
			}
			i++;
		}
		j++;
	}
	if (flag != 1)
		data->zooming_factor = 0.85;
}

void	reset_hook(t_vars_mlx *data)
{
	clear_window(data);
	reset_parameters(data, 42, 0, 0);
	put_grid(&(data->img), data);
	print_menu(data, 1);
}

void	set_parallel(t_vars_mlx *data)
{
	int		x;
	int		y;
	
	y = 0;
	while (y < data->matrix_y)
	{
		x = 0;
		while (data->map[y][x].color != -1)
		{
			data->map[y][x].screen_x *= data->zoom;
			data->map[y][x].screen_y *= data->zoom;
			data->map[y][x].screen_x += data->offset_x;
			data->map[y][x].screen_y += data->offset_y;
			x++;
		}
		y++;
	}
}

void	parallel_hook(t_vars_mlx *data)
{
	clear_window(data);
	reset_parameters(data, 1, 0, 0);
	max_and_min_Y(data);
	max_and_min_X(data);
	find_zoom(data);
	data->offset_x = offset_x(data);
	data->offset_y = offset_y(data);
	set_parallel(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	print_menu(data, 42);
}

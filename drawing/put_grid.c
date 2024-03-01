/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:13:54 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/01 18:22:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	apply_changes(t_point **map, t_vars_mlx *data, int matrix_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			(&map[y][x])->screen_x *= data->zoom;
			(&map[y][x])->screen_y *= data->zoom;
			(&map[y][x])->screen_x += data->offset_x;
			(&map[y][x])->screen_y += data->offset_y;
			x++;
		}
		y++;
	}
}

static int	offset_x(t_vars_mlx *data)
{
	t_point	**map;
	int		m_x;
	int		m_y;
	int		total_width;
	int		offset_x;

	map = data->map;
	m_x = calculate_x(map) - 1;
	m_y = calculate_y(data->map_file) - 1;
	total_width = ((map[m_y][m_x].screen_x - map[0][0].screen_x) * data->zoom) / 2;
	offset_x = (WIDTH / 2) - total_width;
	return (offset_x);
}

static int	offset_y(t_vars_mlx *data)
{
	float	total_height;
	int		middle_Y;
	int		offset_y;
	
	total_height = ((data->Y_max - data->Y_min) * data->zoom) / 2;
	middle_Y = (data->Y_max * data->zoom) - total_height;
	offset_y = (HEIGHT / 2) - middle_Y;
	return (offset_y);
}

static void	find_zoom(t_vars_mlx *data)
{
	float	c;
	float	d_X;
	float	d_Y;

	c = 0.9;
	d_X = data->X_max - data->X_min;
	d_Y = data->Y_max - data->Y_min;
	if (d_Y > d_X)
		data->zoom = c * (HEIGHT / d_Y);
	else
		data->zoom = c * (WIDTH / d_X);
	if (data->zoom <= 0)
		data->zoom = 0.1;
}

void	put_grid(t_point **map, t_data *img, t_vars_mlx mlx_data, int matrix_y)
{
	int	x;
	int	y;

	img->img = mlx_new_image(mlx_data.mlx, HEIGHT, WIDTH);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	apply_isometric(mlx_data.map, matrix_y);
	max_and_min_Y(map, matrix_y, &mlx_data);
	max_and_min_X(&mlx_data);
	find_zoom(&mlx_data);
	mlx_data.offset_x = offset_x(&mlx_data);
	mlx_data.offset_y = offset_y(&mlx_data);
	apply_changes(map, &mlx_data, matrix_y);
	y = 0;
	while (y < matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			// printf("x: %.2f -- y: %.2f\n", map[y][x].screen_x, map[y][x].screen_y); 
			// float tmp_x = (map[y][x].screen_x * mlx_data.zoom) + mlx_data.offset_x;
			// float tmp_y = (map[y][x].screen_y * mlx_data.zoom) + mlx_data.offset_y;

			float tmp_x = map[y][x].screen_x;
			float tmp_y = map[y][x].screen_y;
			if (map[y][x].color == 0 && tmp_x >= 0 && tmp_y >= 0)
			{
				// printf("final_x: %.2f final_y: %.2f || x: %.2f -- y:%.2f\n\n", tmp_x, tmp_y, map[y][x].x, map[y][x].y);
				ft_pixel_put(img, (int)tmp_x, (int)tmp_y, 0xFF0000);
			}
			else if (tmp_x >= 0 && tmp_y >= 0)
				ft_pixel_put(img, (int)tmp_x, (int)tmp_y, map[y][x].color);
			x++;
		}
		y++;
	}
	draw_map(&mlx_data, matrix_y, img);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, img->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:13:54 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/05 18:16:43 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_changes(t_point **map, t_vars_mlx *data, int matrix_y)
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

int	offset_x(t_vars_mlx *data)
{
	t_point	**map;
	int		m_x;
	int		m_y;
	int		total_width;
	int		offset_x;

	map = data->map;
	m_x = calculate_x(map) - 1;
	m_y = calculate_y(data->map_file) - 1;
	total_width = ((map[m_y][m_x].screen_x - map[0][0].screen_x)
			* data->zoom) / 2;
	offset_x = (WIDTH / 2) - total_width;
	return (offset_x);
}

int	offset_y(t_vars_mlx *data)
{
	float	total_height;
	int		middle_y;
	int		offset_y;

	total_height = ((data->y_max - data->y_min) * data->zoom) / 2;
	middle_y = (data->y_max * data->zoom) - total_height;
	offset_y = (HEIGHT / 2) - middle_y;
	return (offset_y);
}

void	find_zoom(t_vars_mlx *data)
{
	float	c;
	float	d_x;
	float	d_y;

	c = 0.85;
	d_x = data->x_max - data->x_min;
	d_y = data->y_max - data->y_min;
	if (d_y > d_x)
		data->zoom = c * (HEIGHT / d_y);
	else
		data->zoom = c * (WIDTH / d_x);
	if (data->zoom <= 0)
		data->zoom = 0.1;
}

void	draw_points_only(t_vars_mlx *data)
{
	int		x;
	int		y;
	float	tmp_x;
	float	tmp_y;
	
	y = 0;
	while (y < data->matrix_y)
	{
		x = 0;
		while (data->map[y][x].color != -1)
		{
			tmp_x = data->map[y][x].screen_x;
			tmp_y = data->map[y][x].screen_y;
			if (data->map[y][x].color == 0 && tmp_x >= 0 && tmp_y >= 0)
				ft_pixel_put(&(data->img), (int)tmp_x, (int)tmp_y, 0xFFFFFF);
			else if (tmp_x >= 0 && tmp_y >= 0)
				ft_pixel_put(&(data->img), (int)tmp_x, (int)tmp_y, data->map[y][x].color);
			x++;
		}
		y++;
	}
}

void	put_grid(t_data *img, t_vars_mlx *data)
{
	apply_isometric(data->map, data);
	max_and_min_Y(data->map, data->matrix_y, data);
	max_and_min_X(data);
	find_zoom(data);
	data->zoom_0 = data->zoom;
	data->offset_x = offset_x(data);
	data->offset_y = offset_y(data);
	apply_changes(data->map, data, data->matrix_y);
	// draw_points_only(data);
	draw_map(data, data->matrix_y, img);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}

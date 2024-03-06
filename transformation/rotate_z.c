/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:30:59 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/06 16:26:36 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	find_center(t_vars_mlx *data)
{
	// data->center_x = data->map[calculate_x(data->map) / 2][calculate_y(data->map_file) / 2].screen_x;
	// data->center_y = data->map[calculate_x(data->map) / 2][calculate_y(data->map_file) / 2].screen_y;
	max_and_min_X(data);
	max_and_min_Y(data->map, data->matrix_y, data);
	data->center_x = ((data->x_max - data->x_min) / 2) + data->offset_x;
	data->center_y = ((data->y_max - data->y_min) / 2) + data->offset_y;
	printf("Y values: max -> %.2f min -> %.2f\n", data->y_max, data->y_min);
	printf("center: %.2f - %.2f\n", data->center_x, data->center_y);
}

void	rotate_z(t_point *point, t_vars_mlx *data)
{
	float	new_x;
	float	new_y;

	float rad = (data->angle_z * PI) / 180.0;

    new_x = (cos(rad)) * (point->screen_x - data->center_x) - sin(rad) * (point->screen_y - data->center_y) + data->center_x;
    new_y = (sin(rad)) * (point->screen_x - data->center_x) + cos(rad) * (point->screen_y - data->center_y) + data->center_y;
	// printf("screen coordinates: %.2f - %.2f\n", point->screen_x, point->screen_y);
	// printf("new coordinates: %.2f - %.2f\n", new_x, new_y);
    point->screen_x = new_x;
    point->screen_y = new_y;
}

void	apply_rotation(t_vars_mlx *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->matrix_y)
	{
		x = 0;
		while (data->map[y][x].color != -1)
		{
			rotate_z(&(data->map[y][x]), data);
			// printf("new screen coordinates: %.2f - %.2f\n\n", data->map[y][x].screen_x, data->map[y][x].screen_y);
			// data->map[y][x].screen_x *= data->zoom_0;
			// data->map[y][x].screen_y *= data->zoom_0;
			x++;
		}
		y++;
	}
}

void	rotate_z_hooks(int keysym, t_vars_mlx *data)
{
	if (keysym == ROTATE_Z_LEFT)
	{
		if (data->angle_z == 360)
			data->angle_z = 0;
		data->angle_z += 1.00;
	}
	if (keysym == ROTATE_Z_RIGHT)
	{
		if (data->angle_z == 0)
			data->angle_z = 360;
		data->angle_z -= 1.00;
	}
	clear_window(data);
	find_center(data);
	// apply_isometric(data->map, data);
	// apply_changes(data->map, data, data->matrix_y);
	apply_rotation(data);
	// printf("new screen coordinates: %.2f - %.2f\n", point->screen_x, point->screen_y);
	draw_map(data, data->matrix_y, &(data->img));
	
	// ft_pixel_put(&(data->img), (int)data->center_x, (int)data->center_y, 0xFFFFFF);
	
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	// put_grid(&(data->img), *data);
}

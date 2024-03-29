/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:07:34 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/11 14:44:59 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_around_z(t_point *point, float angle)
{
	float	angleRadians;
	float	new_x;
	float	new_y;

	angleRadians = angle * PI / 180.0;
    new_x = point->final_x * cos(angleRadians) - point->final_y * sin(angleRadians);
    new_y = point->final_x * sin(angleRadians) + point->final_y * cos(angleRadians);
    point->screen_x = new_x;
    point->screen_y = new_y;
}

void	isometric(t_point *point, t_vars_mlx *data)
{
	float	angle_x;
	float	angle_y;

    angle_x = 35.0 * PI / 180.0;
    angle_y = 30.0 * PI / 180.0;

    // Rotation around the X-axis
    point->isometric_x = point->x;
    point->isometric_y = point->y * cos(angle_x) - point->z * sin(angle_x);
    point->isometric_z = point->y * sin(angle_x) + point->z * cos(angle_x);

    // Rotation around the Y-axis
    point->final_x = point->isometric_x * cos(angle_y) -  point->isometric_z * sin(angle_y);
    point->final_y = point->isometric_y;

    // Orthographic projection (dropping the Z-axis)
    point->screen_x = point->final_x;
    point->screen_y = point->final_y;
	point->reset_s_x = point->screen_x;
    point->reset_s_y = point->screen_y;
	
	rotate_around_z(point, data->angle_z);
}

void	apply_isometric(t_point **map, t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->matrix_y)
	{
		i = 0;
		while (map[j][i].color != -1)
		{
			isometric(&map[j][i], data);
			i++;
		}
		j++;
	}
}

void	max_and_min_Y(t_vars_mlx *data)
{
	int		j;
	int		i;
	float	max;
	float	min;
	
	j = 0;
	max = (float)INT_MIN;
	min = (float)INT_MAX;
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			if (data->map[j][i].screen_y > max)
				max = data->map[j][i].screen_y;
			if (data->map[j][i].screen_y < min)
				min = data->map[j][i].screen_y;
			i++;
		}
		j++;
	}
	data->y_max = max;
	data->y_min = min;
}

void	max_and_min_X(t_vars_mlx *data)
{
	t_point	**map;
	int		m_x;
	int		m_y;
	
	map = data->map;
	m_x = calculate_x(map) - 1;
	m_y = calculate_y(data->map_file) - 1;
	data->x_min = map[m_y][0].screen_x;
	data->x_max = map[0][m_x].screen_x;
}

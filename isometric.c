/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:07:34 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/29 17:02:10 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	rotate_around_z(t_point *point, float angle)
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

static void	isometric(t_point *point)
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

	// Rotation around z
	rotate_around_z(point, 30);
}

void	apply_isometric(t_point **map, int matrix_y)
{
	int	i;
	int	j;

	j = 0;
	while (j < matrix_y)
	{
		i = 0;
		while (map[j][i].color != -1)
		{
			isometric(&map[j][i]);
			i++;
		}
		j++;
	}
}

void	max_and_min_Y(t_point **map, int matrix_y, t_vars_mlx *data)
{
	int		j;
	int		i;
	float	max;
	float	min;
	
	j = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (j < matrix_y)
	{
		i = 0;
		while (map[j][i].color != -1)
		{
			if (map[j][i].screen_y > max)
				max = map[j][i].screen_y;
			if (map[j][i].screen_y < min)
				min = map[j][i].screen_y;
			i++;
		}
		j++;
	}
	data->Y_max = max;
	data->Y_min = min;
}

void	max_and_min_X(t_vars_mlx *data)
{
	t_point	**map;
	int		m_x;
	int		m_y;
	
	map = data->map;
	m_x = calculate_x(map) - 1;
	m_y = calculate_y(data->map_file) - 1;
	data->X_min = map[m_y][0].screen_x;
	data->X_max = map[0][m_x].screen_x;
}

	// printf("isomt_x: %.2f isomt_y: %.2f isomt_z: %.2f\n", point->isometric_x, point->isometric_y, point->isometric_z);
	// printf("final_x: %.2f final_y: %.2f\n\n", point->final_x, point->final_y);
	// printf("final_x: %.2f final_y: %.2f\n", point->screen_x, point->screen_y);
	// printf("rotate Z _x: %.2f _y: %.2f\n", point->screen_x, point->screen_y);
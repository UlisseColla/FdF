/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_definition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:04:45 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/12 18:33:26 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	max_and_min_Z(t_vars_mlx *data, int i, int j)
{
	int		max;
	int		min;

	max = INT_MIN;
	min = INT_MAX;
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			if (data->map[j][i].z > max)
				max = data->map[j][i].z;
			if (data->map[j][i].z < min)
				min = data->map[j][i].z;
			i++;
		}
		j++;
	}
	data->z_max = max;
	data->z_min = min;
}

void	put_base_colors(t_point *point, int flag)
{
	int	r;
	int	g;
	int	b;

	r = 255;
	g = 255;
	b = 255;
	if (flag == 1)
	{
		r = 0;
		g = 0;
		b = 255;
	}
	else if (flag == 2)
	{
		r = 255;
		g = 0;
		b = 0;
	}
	point->color = (r << 16) | (g << 8) | b;
}

void	calculate_rgb(t_point *point, t_vars_mlx *data, int flag)
{
	int	r;
	int	g;
	int	b;
	
	r = (point->color  >> 16) & 0xFF;
	g = (point->color >> 8) & 0xFF;
	b = point->color & 0xFF;
	if (flag == 1)
	{
		r = 255;
		g = 255 - (point->z - data->z_max) * 10;
		b = 255 - (point->z - data->z_max) * 10;
	}
	else
	{
		r = 255 + (point->z - data->z_min) * 10;
		g = 255 + (point->z - data->z_min) * 10;
		b = 255;
	}
	point->color = (r << 16) | (g << 8) | b;
}

void	define_colors(t_vars_mlx *data, int i, int j)
{
	int		max;
	int		min;

	max = INT_MIN;
	min = INT_MAX;
	max_and_min_Z(data, 0, 0);
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			if (data->map[j][i].z == 0)
				put_base_colors(&(data->map[j][i]), 42);
			else if (data->map[j][i].z == data->z_max)
				put_base_colors(&(data->map[j][i]), 2);
			else if (data->map[j][i].z == data->z_min)
				put_base_colors(&(data->map[j][i]), 1);
			else if (data->map[j][i].z > 0 && data->map[j][i].z != data->z_max)
				calculate_rgb(&(data->map[j][i]), data, 1);
			else if (data->map[j][i].z < 0 && data->map[j][i].z != data->z_min)
				calculate_rgb(&(data->map[j][i]), data, 42);
			i++;
		}
		j++;
	}
}

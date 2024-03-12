/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_grid_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:03:57 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/11 15:04:19 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
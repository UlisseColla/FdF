/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:13:54 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/27 18:30:58 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	offset_x(t_point **map)
{
	int	offset_x;
	int	width_map;

	width_map = calculate_x(map);
	offset_x = (WIDTH - width_map) / 2;
	return (offset_x);
}

int	offset_y(char *map_file)
{
	int	offset_y;
	int	height_map;

	height_map = calculate_y(map_file);
	offset_y = (HEIGHT - height_map) / 2;
	return (offset_y);
}

// float	zoom(int offset_x, int offset_y)
// {
		
// }

void	put_grid(t_point **map, t_data *img, t_vars_mlx mlx_data, int matrix_y)
{
	// float	zoom;
	// float	offset;
	int	x;
	int	y;

	img->img = mlx_new_image(mlx_data.mlx, HEIGHT, WIDTH);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	mlx_data.offset_x = offset_x(map);
	mlx_data.offset_y = offset_y(mlx_data.map_file);
	y = 0;
	while (y < matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			isometric(&map[y][x]);
			float tmp_x = (map[y][x].screen_x * 1.5) + mlx_data.offset_x; //(map[y][x].screen_x * zoom) + offset_x
			float tmp_y = (map[y][x].screen_y * 1.5) + mlx_data.offset_y / 2; //(map[y][x].screen_x * zoom) + offset_y
			if (map[y][x].color == 0 && tmp_x >= 0 && tmp_y >= 0)
			{
				// printf("final_x: %.2f final_y: %.2f || x: %.2f -- y:%.2f\n\n", tmp_x, tmp_y, map[y][x].x, map[y][x].y);
				ft_pixel_put(img, (int)tmp_x, (int)tmp_y, 0xFFFFFF);
			}
			else if (tmp_x >= 0 && tmp_y >= 0)
					ft_pixel_put(img, (int)tmp_x, (int)tmp_y, map[y][x].color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, img->img, 0, 0);
}

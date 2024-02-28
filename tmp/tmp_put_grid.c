/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_put_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:00:52 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/28 16:37:06 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* int	offset_x(t_point **map)
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
} */

void	tmp_put_grid(t_point **map, t_data *img, t_vars_mlx mlx_data, int matrix_y)
{
	int	x;
	int	y;
	// float	offset;
	float	format;

	img->img = mlx_new_image(mlx_data.mlx, HEIGHT, WIDTH);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	format = padding(map, matrix_y);
	printf("format: %.2f\n", format);
	y = 0;
	// offset = 100;
	while (y < matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			printf("final_x: %.2f final_y: %.2f\n", (map[y][x].screen_x * format), (map[y][x].screen_y * format));
			if (map[y][x].color == 0)
			{
				// printf("final_x: %.2f final_y: %.2f || x: %.2f -- y:%.2f\n", (map[y][x].screen_x * format + offset), (map[y][x].screen_y * format + offset), map[y][x].x, map[y][x].y);
				ft_pixel_put(img, ((map[y][x].x) + 100), ((map[y][x].y) + 150), 0xFFFFFF);
			}
			else
				ft_pixel_put(img, ((map[y][x].x) + 100), ((map[y][x].y) + 150), map[y][x].color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, img->img, 0, 0);
}

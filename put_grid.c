/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:13:54 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/28 19:03:12 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static int	offset_x(t_vars_mlx data, float zoom)
{
	t_point	**map;
	int		m_x;
	int		m_y;
	int		total_width;
	int		offset_x;

	map = data.map;
	m_x = calculate_x(map) - 1;
	m_y = calculate_y(data.map_file) - 1;
	total_width = ((map[m_y][m_x].screen_x - map[0][0].screen_x) * zoom) / 2;
	offset_x = (WIDTH / 2) - total_width;
	return (offset_x);
}

static int	offset_y(t_vars_mlx data, float zoom)
{
	int		total_height;
	int		offset_y;
	
	total_height = ((data.Y_max - data.Y_min) * zoom) / 2;
	offset_y = (HEIGHT / 2) - total_height;
	return (offset_y);
}

void	put_grid(t_point **map, t_data *img, t_vars_mlx mlx_data, int matrix_y)
{
	float	zoom;
	int	x;
	int	y;

	zoom = 1.20;
	img->img = mlx_new_image(mlx_data.mlx, HEIGHT, WIDTH);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	apply_isometric(mlx_data.map, matrix_y);
	max_and_min_Y(map, matrix_y, &mlx_data);
	mlx_data.offset_x = offset_x(mlx_data, zoom);
	mlx_data.offset_y = offset_y(mlx_data, zoom);
	y = 0;
	while (y < matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			// printf("x: %.2f -- y: %.2f\n", map[y][x].screen_x, map[y][x].screen_y); 
			float tmp_x = (map[y][x].screen_x * zoom) + mlx_data.offset_x;
			float tmp_y = (map[y][x].screen_y * zoom) + mlx_data.offset_y;
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

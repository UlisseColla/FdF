/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:58:29 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/05 18:15:56 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* static void	apply_changes(t_point **map, t_vars_mlx *data)
{
	int	x;
	int	y;

	y = 0;
	printf("zoom: %.2f\n", data->zoom);
	while (y < data->matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			(&map[y][x])->screen_x *= data->zoom;
			(&map[y][x])->screen_y *= data->zoom;
			// (&map[y][x])->screen_x += data->offset_x;
			// (&map[y][x])->screen_y += data->offset_y;
			x++;
		}
		y++;
	}
} */

void	zoom_in(t_vars_mlx *data)
{
	data->zoom += 0.05;
}

void	zoom_out(t_vars_mlx *data)
{
	data->zoom -= 0.05;
}

void	zoom_hooks(int keysym, t_vars_mlx *data)
{
	if (keysym == ZOOM_IN)
		zoom_in(data);
	if (keysym == ZOOM_OUT)
		zoom_out(data);
	
	clear_window(data);
	// apply_changes(data->map, data);
	put_grid(&(data->img), data);
	// draw_map(data, data->matrix_y, data->img);
	// mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:58:29 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/11 12:22:15 by ucolla           ###   ########.fr       */
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

void	zoom_hooks(int keysym, t_vars_mlx *data)
{
	if (keysym == ZOOM_IN)
		data->zooming_factor += 0.05;
	if (keysym == ZOOM_OUT)
		data->zooming_factor -= 0.05;
	
	clear_window(data);
	put_grid(&(data->img), data);
}
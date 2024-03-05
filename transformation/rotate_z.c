/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:30:59 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/05 18:18:33 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			// data->map[y][x].screen_x += data->offset_x;
			// data->map[y][x].screen_y += data->offset_y;
			rotate_around_z(&(data->map[y][x]), data->angle_z);
			data->map[y][x].screen_x *= data->zoom_0;
			data->map[y][x].screen_y *= data->zoom_0;
			x++;
		}
		y++;
	}
}

void	rotate_z_hooks(int keysym, t_vars_mlx *data)
{
	(void)data;
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
		
	/* Trovare funzione che ricentra l'immagine con offset_x e offset_y */
	
	clear_window(data);
	// apply_isometric(data->map, data);
	// draw_map(data, data->matrix_y, &(data->img));
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	// apply_isometric(data->map, data);
	max_and_min_Y(data->map, data->matrix_y, data);
	max_and_min_X(data);
	find_zoom(data);
	printf("zoom_0: %.2f\n", data->zoom_0);

	data->offset_x = offset_x(data);
	data->offset_y = offset_y(data);
	apply_changes(data->map, data, data->matrix_y);
	apply_rotation(data);
	draw_map(data, data->matrix_y, &(data->img));
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	// put_grid(&(data->img), *data);
}

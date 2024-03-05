/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:21:08 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/05 16:41:27 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_window(t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			ft_pixel_put(&(data->img), i, j, 0x000000);
			i++;
		}
		j++;
	}
}

// void	reset_hook(t_vars_mlx *data)
// {
// 	clear_window(data);
// 	draw_map(data, data->matrix_y, data->img);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
// }

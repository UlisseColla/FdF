/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:13:43 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/12 19:09:13 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu_controls(t_vars_mlx *data)
{
	mlx_string_put(data->mlx, data->menu_win, 50, 50, 0xFFFFFF, "CONTROLS");
}

void	print_menu(t_vars_mlx *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < MENU_H)
	{
		x = 0;
		while (x < MENU_W)
		{
			ft_pixel_put(&(data->menu_img), x, y, 0xFF9999);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->menu_win, data->menu_img.img, 0, 0);
	menu_controls(data);
}


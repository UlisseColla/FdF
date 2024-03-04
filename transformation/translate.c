/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:28:58 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/04 19:26:41 by ucolla           ###   ########.fr       */
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
		i = MENU_WIDTH;
		while (i < WIDTH + MENU_WIDTH)
		{
			ft_pixel_put(data->img, i, j, 0x000000);
			i++;
		}
		j++;
	}
}

int	translate_right(t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			data->map[j][i].screen_x += 5;
			i++;
		}
		j++;
	}
	return (0);
}

int	translate_left(t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			data->map[j][i].screen_x -= 5;
			i++;
		}
		j++;
	}
	return (0);
}

int	translate_up(t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			data->map[j][i].screen_y -= 5;
			i++;
		}
		j++;
	}
	return (0);
}

int	translate_down(t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			data->map[j][i].screen_y += 5;
			i++;
		}
		j++;
	}
	return (0);
}

void	translate_hooks(int keysym, t_vars_mlx *data)
{
	if (keysym == UP)
		translate_up(data);
	if (keysym == DOWN)
		translate_down(data);
	if (keysym == RIGHT)
		translate_right(data);
	if (keysym == LEFT)
		translate_left(data);

	// mlx_clear_window(data->mlx, data->win);
	clear_window(data);
	draw_map(data, data->matrix_y, data->img);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

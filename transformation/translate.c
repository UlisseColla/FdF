/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:28:58 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/05 16:40:39 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

	clear_window(data);
	draw_map(data, data->matrix_y, &(data->img));
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

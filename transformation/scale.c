/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:12:18 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/13 17:18:06 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	scale_up(t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			if (data->map[j][i].x != 0)
				data->map[j][i].x /= 1.1;
			if (data->map[j][i].y != 0)
				data->map[j][i].y /= 1.1;
			i++;
		}
		j++;
	}
}

void	scale_down(t_vars_mlx *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->matrix_y)
	{
		i = 0;
		while (data->map[j][i].color != -1)
		{
			if (data->map[j][i].x != 0)
				data->map[j][i].x *= 1.1;
			if (data->map[j][i].y != 0)
				data->map[j][i].y *= 1.1;
			i++;
		}
		j++;
	}
}

void	scale_hooks(int keysym, t_vars_mlx *data)
{
	if (keysym == Z_UP)
		scale_up(data);
	if (keysym == Z_DOWN)
		scale_down(data);
		
	clear_window(data);
	put_grid(&(data->img), data);
	print_menu(data, 1);
}
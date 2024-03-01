/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:55:46 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/01 18:32:36 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_vertical(t_point *p_1, t_point *p_2, t_data *img)
{
	int	x;
	int	y;

	x = (int)p_1->screen_x;
	y = (int)p_1->screen_y;
	while (y <= (int)p_2->screen_y)
	{
		ft_pixel_put(img, (int)x, (int)y, 0xFFFFFF);
		y++;
	}
}

void	draw_horizontal(t_point *p_1, t_point *p_2, t_data *img)
{
	int	x;
	int	y;

	x = (int)p_1->screen_x;
	y = (int)p_1->screen_y;
	while (x <= (int)p_2->screen_x)
	{
		ft_pixel_put(img, (int)x, (int)y, 0xFFFFFF);
		x++;
	}
}

void	draw_line(t_point *p_1, t_point *p_2, t_data *img)
{
	int		x_1;
	int		y_1;
	int		x_2;
	int		y_2;
	float	d_X;
	float	d_Y;
	float	slope;
	float	decision;

	x_1 = (int)p_1->screen_x;
	y_1 = (int)p_1->screen_y;
	x_2 = (int)p_2->screen_x;
	y_2 = (int)p_2->screen_y;
	d_X = x_2 - x_1;
	d_Y = y_2 - y_1;
	if (d_X == 0)
	{
		draw_vertical(p_1, p_2, img);
		return ;
	}
	if (d_Y == 0)
	{
		draw_horizontal(p_1, p_2, img);
		return ;
	}
	slope = d_Y / d_X;
	if (slope <= 1 && slope >= -1)
	{
		if (d_Y < 0)
			d_Y *= -1;
		if (d_X < 0)
			d_X *= -1;
		decision = (2 * d_Y) - d_X;
		while (x_1 != x_2)
		{
			if (x_1 >= 0 && y_1 >= 0)
				ft_pixel_put(img, x_1, y_1, 16777215);
			if (x_1 < x_2)
				x_1++;
			else
				x_1--;
			if (decision < 0)
				decision += (2 * d_Y);
			else
			{
				decision += (2 * d_Y) - (2 * d_X);
				if (y_1 < y_2)
					y_1++;
				else
					y_1--;
			}
		}
	}
	else
	{
		if (d_Y < 0)
			d_Y *= -1;
		if (d_X < 0)
			d_X *= -1;
		decision = (2 * d_X) - d_Y;
		while (y_1 != y_2)
		{
			if (x_1 >= 0 && y_1 >= 0)
				ft_pixel_put(img, x_1, y_1, 16777215);
			if (y_1 < y_2)
				y_1++;
			else
				y_1--;
			if (decision < 0)
				decision += (2 * d_X);
			else
			{
				decision += ((2 * d_X) - (2 * d_Y));
				if (x_1 < x_2)
					x_1++;
				else
					x_1--;
			}
		}
	}
}

void	draw_map(t_vars_mlx *data, int matrix_y, t_data *img)
{
	int	x;
	int	y;
	t_point	**map;
	
	map = data->map;
	y = 0;
	while (y < matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			if (map[y][x + 1].color != -1)
				draw_line(&map[y][x], &map[y][x + 1], img); //right
			if (y < matrix_y - 1)
				draw_line(&map[y][x], &map[y + 1][x], img); //down
			x++;
		}
		y++;
	}
}

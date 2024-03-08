/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:55:46 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/08 14:08:01 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	more_horizontal(t_draw *info, t_data *img)
{
	info->decision = (2 * info->d_y) - info->d_x;
	set_steps(info);
	set_draw_color(info);
	while (info->x_1 != info->x_2)
	{
		if ((info->x_1 > 0 && info->x_1 < WIDTH) && (info->y_1 > 0 && info->y_1 < HEIGHT))
			ft_pixel_put(img, (int)info->x_1, (int)info->y_1, info->draw_color);
		if (info->x_1 < info->x_2)
			info->x_1++;
		else
			info->x_1--;
		if (info->decision < 0)
			info->decision += (2 * info->d_y);
		else
		{
			info->decision += (2 * info->d_y) - (2 * info->d_x);
			if (info->y_1 < info->y_2)
				info->y_1++;
			else
				info->y_1--;
		}
		set_color_param(info);
	}
}

static void	more_vertical(t_draw *info, t_data *img)
{
	info->decision = (2 * info->d_x) - info->d_y;
	set_steps(info);
	set_draw_color(info);
	while (info->y_1 != info->y_2)
	{
		if ((info->x_1 > 0 && info->x_1 < WIDTH) && (info->y_1 > 0 && info->y_1 < HEIGHT))
			ft_pixel_put(img, (int)info->x_1, (int)info->y_1, info->draw_color);
		if (info->y_1 < info->y_2)
			info->y_1++;
		else
			info->y_1--;
		if (info->decision < 0)
			info->decision += (2 * info->d_x);
		else
		{
			info->decision += ((2 * info->d_x) - (2 * info->d_y));
			if (info->x_1 < info->x_2)
				info->x_1++;
			else
				info->x_1--;
		}
		set_color_param(info);
	}
}

static void	draw_info_init(t_draw *info, t_point *p_1, t_point *p_2)
{
	info->x_1 = p_1->screen_x;
	info->y_1 = p_1->screen_y;
	info->x_2 = p_2->screen_x;
	info->y_2 = p_2->screen_y;
	info->start_r = (p_1->color  >> 16) & 0xFF;
	info->start_g = (p_1->color >> 8) & 0xFF;
	info->start_b = p_1->color & 0xFF;
	info->end_r = (p_2->color  >> 16) & 0xFF;
	info->end_g = (p_2->color >> 8) & 0xFF;
	info->end_b = p_2->color & 0xFF;
	info->tmp_r = info->start_r;
	info->tmp_g = info->start_g;
	info->tmp_b = info->start_b;
	info->steps_r = 0;
	info->steps_g = 0;
	info->steps_b = 0;
	info->d_r = (float)(info->end_r - info->start_r);
	info->d_g = (float)(info->end_g - info->start_g);
	info->d_b = (float)(info->end_b - info->start_b);
	info->draw_color = 0;
	info->d_x = abs(info->x_2 - info->x_1);
	info->d_y = abs(info->y_2 - info->y_1);
	info->n_step = (int)(fmax(info->d_x, info->d_y) - 1);
	info->slope = 0;
	info->decision = 0;
}

void	draw_line(t_point *p_1, t_point *p_2, t_data *img)
{
	t_draw	info;

	draw_info_init(&info, p_1, p_2);
	if (info.d_x == 0)
	{
		draw_vertical(&info, p_1, p_2, img);
		return ;
	}
	if (info.d_y == 0)
	{
		draw_horizontal(&info, p_1, p_2, img);
		return ;
	}
	info.slope = info.d_y / info.d_x;
	if (info.slope <= 1 && info.slope >= -1)
		more_horizontal(&info, img);
	else
		more_vertical(&info, img);
}

void	draw_map(t_vars_mlx *data, int matrix_y, t_data *img)
{
	int		x;
	int		y;
	
	y = 0;
	while (y < matrix_y)
	{
		x = 0;
		while (data->map[y][x].color != -1)
		{
			if (data->map[y][x + 1].color != -1)
				draw_line(&(data->map[y][x]), &(data->map[y][x + 1]), img);
			if (y < matrix_y - 1)
				draw_line(&(data->map[y][x]), &(data->map[y + 1][x]), img);
			x++;
		}
		y++;
	}
}

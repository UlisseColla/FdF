/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:38:18 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/05 15:40:56 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	absolute_value(float value)
{
	if (value < 0)
		value *= -1;
	return (value);
}

void	draw_vertical(t_draw *info, t_point *p_1, t_point *p_2, t_data *img)
{
	float	x;
	float	y;

	x = p_1->screen_x;
	y = p_1->screen_y;
	set_steps(info);
	set_draw_color(info);
	while (y <= p_2->screen_y)
	{
		if (((int)x > 0 && (int)x < WIDTH) && ((int)y > 0 && (int)y < HEIGHT))
			ft_pixel_put(img, (int)x, (int)y, info->draw_color);
		y++;
		set_color_param(info);
	}
}

void	draw_horizontal(t_draw *info, t_point *p_1, t_point *p_2, t_data *img)
{
	float	x;
	float	y;

	x = p_1->screen_x;
	y = p_1->screen_y;
	set_steps(info);
	set_draw_color(info);
	while (x <= p_2->screen_x)
	{
		if (((int)x > 0 && (int)x < WIDTH) && ((int)y > 0 && (int)y < HEIGHT))
			ft_pixel_put(img, (int)x, (int)y, info->draw_color);
		x++;
		set_color_param(info);
	}
}
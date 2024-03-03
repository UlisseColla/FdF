/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:38:18 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/03 16:54:11 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	absolute_value(float value)
{
	if (value < 0)
		value *= -1;
	return (value);
}

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
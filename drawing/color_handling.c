/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:09:20 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/03 20:14:14 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* static void	save_rgb(t_draw *info, t_point *p_1, t_point *p_2)
{
	info->steps = fmax(info->d_x, info->d_y) - 1;
} */

static void set_tmp_rgb(t_draw *info)
{
	info->draw_color = ((int)info->tmp_r << 16)
		| ((int)info->tmp_g << 8)
		| (int)info->tmp_b;
	// printf("color: %d\n", info->draw_color);
	printf("tmp_r: %d\n", ((int)info->tmp_r << 16));
	printf("tmp_g: %d\n", ((int)info->tmp_g << 8));
	printf("tmp_b: %d\n", (int)info->tmp_b);
}

void	set_color_param(t_draw *info)
{
	info->tmp_r += info->steps_r;
	info->tmp_g += info->steps_g;
	info->tmp_b += info->steps_b;
	// printf("steps_r: %d\n", info->steps_r);
	// printf("steps_g: %d\n", info->steps_g);
	// printf("steps_b: %d\n", info->steps_b);
}

void	draw_colors(t_draw *info, t_data *img)
{
	set_tmp_rgb(info);
	ft_pixel_put(img, info->x_1, info->y_1, info->draw_color);
}
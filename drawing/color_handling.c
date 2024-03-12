/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:09:20 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/11 15:38:26 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_steps(t_draw *info)
{
	info->steps_r = info->d_r / info->n_step;
	info->steps_g = info->d_g / info->n_step;
	info->steps_b = info->d_b / info->n_step;
	if (info->d_r == 0)
		info->steps_r = 0;
	else if (info->d_r < 0)
		info->steps_r = (fabs(info->d_r) / info->n_step) * -1;
	if (info->d_g == 0)
		info->steps_g = 0;
	else if (info->d_g < 0)
		info->steps_g = (fabs(info->d_g) / info->n_step) * -1;
	if (info->d_b == 0)
		info->steps_b = 0;
	else if (info->d_b < 0)
		info->steps_b = (fabs(info->d_b) / info->n_step) * -1;
}

void	set_draw_color(t_draw *info)
{
	info->draw_color = ((int)info->tmp_r << 16)
		| ((int)info->tmp_g << 8)
		| (int)info->tmp_b;
}

void	set_color_param(t_draw *info)
{
	info->tmp_r += info->steps_r;
	info->tmp_g += info->steps_g;
	info->tmp_b += info->steps_b;
	set_draw_color(info);
}

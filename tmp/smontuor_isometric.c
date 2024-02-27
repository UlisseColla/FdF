/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smontuor_isometric.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:49:15 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/26 17:59:28 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	isometric_projection(t_fdf *info)
{
	int	i;

	i = 0;
	while (i < info->index)
	{
		info->coords[i].iso_x = (info->zoom.center_x) + ((info->coords[i].x - info->coords[i].y) * cos(PI / 6) * info->zoom.scaling);
		info->coords[i].iso_y = (info->zoom.center_y) - ((info->coords[i].z) * sin(PI / 6) * info->zoom.scaling) + ((info->coords[i].x + info->coords[i].y) * sin(PI / 6) * info->zoom.scaling);
		i++;
	}
	info->zoom.angle = (int)(PI / 6.0 * 180 / PI) + 1;
}
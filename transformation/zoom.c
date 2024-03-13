/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:58:29 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/13 18:49:17 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_hooks(int keysym, t_vars_mlx *data)
{
	if (keysym == ZOOM_IN)
		data->zooming_factor += 0.051;
	if (keysym == ZOOM_OUT)
		data->zooming_factor -= 0.051;

	clear_window(data);
	put_grid(&(data->img), data);
	print_menu(data, 1);
}

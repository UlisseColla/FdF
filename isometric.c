/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:07:34 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/27 17:34:09 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_around_z(t_point *point, float angle)
{
	float	angleRadians;
	float	new_x;
	float	new_y;

	angleRadians = angle * PI / 180.0;
    new_x = point->final_x * cos(angleRadians) - point->final_y * sin(angleRadians);
    new_y = point->final_x * sin(angleRadians) + point->final_y * cos(angleRadians);

    point->screen_x = new_x;
    point->screen_y = new_y;
	// printf("rotate Z _x: %.2f _y: %.2f\n", point->screen_x, point->screen_y);
}

void	isometric(t_point *point)
{
	float	angle_x;
	float	angle_y;

	// Convert angles to radians for rotation
	// angle_x = PI / 6;
	// angle_y = PI / 3;
    angle_x = 35.264 * PI / 180.0;
    angle_y = 30.0 * PI / 180.0;

    // Rotation around the X-axis
    point->isometric_x = point->x;
    point->isometric_y = point->y * cos(angle_x) - point->z * sin(angle_x);
    point->isometric_z = point->y * sin(angle_x) + point->z * cos(angle_x);
	// printf("isomt_x: %.2f isomt_y: %.2f isomt_z: %.2f\n", point->isometric_x, point->isometric_y, point->isometric_z);

    // Rotation around the Y-axis
    point->final_x = point->isometric_x * cos(angle_y) -  point->isometric_z * sin(angle_y);
    point->final_y = point->isometric_y;
	// printf("final_x: %.2f final_y: %.2f\n\n", point->final_x, point->final_y);

    // Orthographic projection (dropping the Z-axis)
    point->screen_x = point->final_x;
    point->screen_y = point->final_y;
	// printf("final_x: %.2f final_y: %.2f\n", point->screen_x, point->screen_y);

	// Rotation around z
	rotate_around_z(point, 30);
}

void	tmp_isometric(t_point *point)
{
	float angle_x = PI / 6; // 30 degrees
    float angle_y = PI / 3; // 60 degrees

    point->screen_x = (point->x - point->y) * cos(angle_x) + 10;
    point->screen_y = -point->z + (point->x + point->y) * sin(angle_y);
	printf("screen_x: %.2f screen_y: %.2f\n", point->screen_x, point->screen_y);
}
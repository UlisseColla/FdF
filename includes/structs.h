/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:58:48 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/08 13:42:36 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_draw
{
	int		x_1;
	int		y_1;
	int		x_2;
	int		y_2;
	int		start_r;
	int		start_g;
	int		start_b;
	int		end_r;
	int		end_g;
	int		end_b;
	float	tmp_r;
	float	tmp_g;
	float	tmp_b;
	float	steps_r;
	float	steps_g;
	float	steps_b;
	float	d_r;
	float	d_g;
	float	d_b;
	int		n_step;
	int		draw_color;
	float	d_x;
	float	d_y;
	float	slope;
	float	decision;
}				t_draw;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	float		isometric_x;
	float		isometric_y;
	float		isometric_z;
	float		final_x;
	float		final_y;
	float		screen_x;
	float		screen_y;
	float		reset_x;
	float		reset_y;
	int			color;
	int			data_set;
}				t_point;

typedef struct s_vars_mlx
{
	char	*map_file;
	int		map_fd;
	void	*mlx;
	void	*win;
	t_point	**map;
	t_data	img;
	int		matrix_y;
	int		offset_x;
	int		offset_y;
	float	y_min;
	float	y_max;
	float	x_min;
	float	x_max;
	float	center_x;
	float	center_y;
	float	zoom;
	float	zoom_0;
	float	angle_z;
	float	zooming_factor;
	// float	offset_x_0;
	// float	offset_y_0;
}				t_vars_mlx;

#endif

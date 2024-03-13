/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:58:48 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/13 16:51:17 by ucolla           ###   ########.fr       */
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
	float		reset_s_x;
	float		reset_s_y;
	float		reset_x;
	float		reset_y;
	int			color;
}				t_point;

typedef struct s_vars_mlx
{
	t_data	img;
	t_data	menu_img;
	t_point	**map;
	void	*mlx;
	void	*win;
	void	*menu_win;
	char	*map_file;
	char	*map_name;
	char	*total_points;
	int		map_fd;
	int		has_color;
	int		matrix_y;
	int		offset_x;
	int		offset_y;
	int		z_min;
	int		z_max;
	float	y_min;
	float	y_max;
	float	x_min;
	float	x_max;
	float	center_x;
	float	center_y;
	float	zoom;
	float	zoom_0;
	float	zooming_factor;
	float	angle_z;
}				t_vars_mlx;

#endif

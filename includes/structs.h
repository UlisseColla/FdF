/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:58:48 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/29 15:59:59 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point {
    float			x;
    float			y;
    float			z;
	float			isometric_x;
	float			isometric_y;
	float			isometric_z;
	float			final_x;
	float			final_y;
	float			screen_x;
	float			screen_y;
    int             color;
    struct s_point  *right;
    struct s_point  *down;
}   			t_point;

typedef struct	s_vars_mlx {
	char	*map_file;
	void	*mlx;
	void	*win;
	t_point **map;
	t_data	img;
	int		matrix_y;
	int		offset_x;
	int		offset_y;
	float	Y_min;
	float	Y_max;
	float	X_min;
	float	X_max;
	float	center_X;
	float	center_Y;
	float	zoom;
}				t_vars_mlx;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:22:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/27 18:12:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 900
# define HEIGHT 900
# define ESCAPE 0xff1b

# define PI 3.14159265358979323846

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line/get_next_line.h"
// # include "./minilibx_macos/mlx.h"

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
}				t_vars_mlx;


int		split_len(char **split);
int 	ft_convert_color(const char *str, char *str_base);

void	show_matrix(int matrix_y, t_point **map);
void	free_matrix(t_point **matrix, int matrix_y);
void	free_split(char **split);

void	ft_pixel_put(t_data *data, int x, int y, int color);
void	put_grid(t_point **map, t_data *img, t_vars_mlx mlx_data, int matrix_y);
void	isometric(t_point *point);

int		calculate_y(char *map_file);
int		calculate_x(t_point **map);
t_point	**build_map(int fd_map, char *map_file);
float	padding(t_point **map, int matrix_y);

/* TMP */
void	tmp_put_grid(t_point **map, t_data *img, t_vars_mlx mlx_data, int matrix_y);
void	tmp_isometric(t_point *point);

#endif
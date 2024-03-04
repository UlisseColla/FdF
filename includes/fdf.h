/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:22:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/04 19:23:28 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 900
# define HEIGHT 900

# define MENU_WIDTH 250

# define ESCAPE 0xff1b
# define UP 0x077
# define DOWN 0x073
# define LEFT 0x061
# define RIGHT 0x064

# define PI 3.14159265358979323846

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "structs.h"
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../../minilibx-linux/mlx.h"
// # include "./minilibx_macos/mlx.h"

/* utils --> fdf_utils */
int					split_len(char **split);
void				show_matrix(int matrix_y, t_point **map);
int					calculate_y(char *map_file);
int					calculate_x(t_point **map);
unsigned long int	convert_color(const char *str);

/* utils --> handle_menu */
void				print_menu(t_vars_mlx *data);

/* utils --> free_and_errors */
int					check_map_extension(char *file, char *extension);
int					ft_error(int flag);
void				free_matrix(t_point **matrix, int matrix_y);
void				free_split(char **split);

/* drawing --> color_handling */
void				draw_colors(t_draw *info, t_data *img);
void				set_draw_color(t_draw *info);
void				set_steps(t_draw *info);
void				set_color_param(t_draw *info);

/* drawing --> draw_utils */
float				absolute_value(float value); // da cambiare con funzione da math.h
void				draw_vertical(t_draw *info, t_point *p_1, t_point *p_2, t_data *img);
void				draw_horizontal(t_draw *info, t_point *p_1, t_point *p_2, t_data *img);

/* drawing --> ft_pixel_put */
void				ft_pixel_put(t_data *data, int x, int y, int color);

/* drawing --> put_grid */
void				put_grid(t_point **map, t_data *img, t_vars_mlx mlx_data, int matrix_y);

/* drawing --> line_drawing */
void				draw_line(t_point *p_1, t_point *p_2, t_data *img);
void				draw_map(t_vars_mlx *data, int matrix_y, t_data *img);

/* transformation --> isometric */
void				apply_isometric(t_point **map, int matrix_y);
void				max_and_min_Y(t_point **map, int matrix_y, t_vars_mlx *data);
void				max_and_min_X(t_vars_mlx *data);

/* transformation --> translate */
void	translate_hooks(int keysym, t_vars_mlx *data);

/* build_map */
t_point				**build_map(int fd_map, char *map_file);

/* TMP */
/* void	tmp_put_grid(t_point **map, t_data *img, t_vars_mlx mlx_data, int matrix_y);
void	tmp_isometric(t_point *point); */

#endif
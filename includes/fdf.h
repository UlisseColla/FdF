/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:22:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/12 18:52:17 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 900
# define HEIGHT 900

# define MENU_W 300
# define MENU_H 400

// # define MENU_WIDTH 250

# define PI 3.14159265358979323846

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "structs.h"
# include "keys.h"
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

/* build_map --> build_map */
void				build_map(t_vars_mlx *data);

/* build_map --> shade_definition */
void				max_and_min_Z(t_vars_mlx *data, int i, int j);
void				calculate_rgb(t_point *point, t_vars_mlx *data, int flag);
void				define_colors(t_vars_mlx *data, int i, int j);

/* drawing --> color_handling */
void				set_draw_color(t_draw *info);
void				set_steps(t_draw *info);
void				set_color_param(t_draw *info);

/* drawing --> draw_utils */
void				draw_vertical(t_draw *info, t_point *p_1, t_point *p_2, t_data *img);
void				draw_horizontal(t_draw *info, t_point *p_1, t_point *p_2, t_data *img);

/* drawing --> ft_pixel_put */
void				ft_pixel_put(t_data *data, int x, int y, int color);

/* drawing --> put_grid */
void				apply_changes(t_point **map, t_vars_mlx *data, int matrix_y);
int					offset_x(t_vars_mlx *data);
int					offset_y(t_vars_mlx *data);
void				put_grid(t_data *img, t_vars_mlx *mlx_data);
void				find_zoom(t_vars_mlx *data);

/* drawing --> put_grid_extra */
void				draw_points_only(t_vars_mlx *data);

/* drawing --> line_drawing */
void				draw_line(t_point *p_1, t_point *p_2, t_data *img);
void				draw_map(t_vars_mlx *data);

/* transformation --> isometric */
void				rotate_around_z(t_point *point, float angle);
void				apply_isometric(t_point **map, t_vars_mlx *data);
void				max_and_min_Y(t_vars_mlx *data);
void				max_and_min_X(t_vars_mlx *data);

/* transformation --> translate */
void				translate_hooks(int keysym, t_vars_mlx *data);

/* transformation --> scale */
void				scale_hooks(int keysym, t_vars_mlx *data);

/* transformation --> zoom */
void				zoom_hooks(int keysym, t_vars_mlx *data);

/* transformation --> rotate_z */
void				rotate_z_hooks(int keysym, t_vars_mlx *data);

/* transformation --> transformation_utils */
void				clear_window(t_vars_mlx *data);
void				reset_hook(t_vars_mlx *data);
void				parallel_hook(t_vars_mlx *data);

/* TMP */
void open_window_at_position(Display *display, int x, int y, unsigned int width, unsigned int height);

#endif
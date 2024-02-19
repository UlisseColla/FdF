/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:22:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/19 18:44:44 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

typedef struct	s_vars_mlx {
	void	*mlx;
	void	*win;
}				t_vars_mlx;

typedef struct s_point {
    int             x;
    int             y;
    int             z;
    int             color;
    struct s_point  *right;
    struct s_point  *down;
}   			t_point;

int	calculate_matrix_y(char *map);
int	calculate_matrix_x(char *map);
int	split_len(char **split);
int ft_convert_color(const char *str, char *str_base);

void	show_matrix(int y, int x, t_point ***map);
void	free_matrix(t_point ***matrix, int matrix_y, int matrix_x);
void	free_split(char **split);

void	ft_pixel_put(t_data *data, int x, int y, int color);

#endif
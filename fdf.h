/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulissecolla <ulissecolla@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:22:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/17 16:04:22 by ulissecolla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line/get_next_line.h"

typedef struct s_point {
    int             x;
    int             y;
    int             z;
    int             color;
    /* struct s_point  *next; */
    struct s_point  *right;
    struct s_point  *down;
}   t_point;

#endif

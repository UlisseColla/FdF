/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:08:56 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/12 17:56:33 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_create_point(t_point *point, float x, float y, float z, int color)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->isometric_x = 0;
	point->isometric_y = 0;
	point->isometric_z = 0;
	point->final_x = 0;
	point->final_y = 0;
	point->screen_x = 0;
	point->screen_y = 0;
	point->color = color;
	point->reset_s_x = 0;
	point->reset_s_y = 0;
	point->reset_x = x;
	point->reset_y = y;
}

static void	create_rows(char **split, int x, int y, t_vars_mlx *data)
{
	char	**z_color;

	z_color = NULL;
	while (split[x] != NULL)
	{
		z_color = ft_split(split[x], ',');
		if (split_len(z_color) > 1)
		{
			ft_create_point(&(data->map[y][x]), x , y, ft_atoi(z_color[0]), convert_color(z_color[1]));
			data->has_color = 1;
		}
		else
			ft_create_point(&(data->map[y][x]), x, y, ft_atoi(*z_color), 0xFFFF00);
		x++;
		free_split(z_color);
	}
	ft_create_point(&(data->map[y][x]), x, y, 0, -1);
}

void	build_map(t_vars_mlx *data)
{
	int	m_x;
	int	y;
	char	*line;
	char	**split;

	data->map = (t_point **)malloc(sizeof(t_point *) * data->matrix_y);
	if (data->map == NULL)
		return ;
	y = 0;
	while (42)
	{
		line = get_next_line(data->map_fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		if (split == NULL) {
            free_matrix(data->map, data->matrix_y);
            return ;
        }
		m_x = split_len(split);
		data->map[y] = (t_point *)malloc((m_x + 1) * sizeof(t_point));
		if (data->map[y] == NULL)
			return ;
		create_rows(split, 0, y, data);
		free_split(split);
		free(line);
		y++;
	}
}

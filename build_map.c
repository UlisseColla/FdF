/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:08:56 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/08 14:20:06 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

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
	point->data_set = 0;
}

static void	create_rows(char **split, int x, int y, t_point **map)
{
	char	**z_color;

	z_color = NULL;
	while (split[x] != NULL)
	{
		z_color = ft_split(split[x], ',');
		if (split_len(z_color) > 1)
			ft_create_point(&map[y][x], x , y, ft_atoi(z_color[0]), convert_color(z_color[1]));
		else if (split_len(z_color) <= 1 && ft_atoi(*z_color) < 1)
			ft_create_point(&map[y][x], x, y, ft_atoi(*z_color), 0x0000FF);
		else if (split_len(z_color) <= 1 && ft_atoi(*z_color) >= 1)
			ft_create_point(&map[y][x], x, y, ft_atoi(*z_color), 0x00FF00);
		x++;
		free_split(z_color);
	}
	ft_create_point(&map[y][x], x, y, 0, -1);
}

t_point	**build_map(t_vars_mlx *data)
{
	int m_y;
	int	m_x;
	t_point	**map;
	int	y;
	char	*line;
	char	**split;

	m_y = calculate_y(data->map_file);
	map = (t_point **)malloc(sizeof(t_point *) * m_y);
	if (map == NULL)
		return (NULL);
	y = 0;
	while (42)
	{
		line = get_next_line(data->map_fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		if (split == NULL) {
            free_matrix(map, m_y);
            return NULL;
        }
		m_x = split_len(split);
		map[y] = (t_point *)malloc((m_x + 1) * sizeof(t_point));
		if (map[y] == NULL)
			return (NULL);
		create_rows(split, 0, y, map);
		free_split(split);
		free(line);
		y++;
	}
	return (map);
}

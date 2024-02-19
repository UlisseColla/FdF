/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/19 18:52:43 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define WIDTH 800
# define HEIGHT 800
# define ESCAPE 0xff1b

t_point	*ft_create_point(int x, int y, int z, int color)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	new->right = NULL;
	new->down = NULL;
	return (new);
}

void	create_rows(char **split, int x, int y, t_point ***map)
{
	char	**z_color;

	z_color = NULL;
	while (split[x] != NULL)
	{
		z_color = ft_split(split[x], ',');
		if (split_len(z_color) > 1)
			map[y][x] = ft_create_point(x, y, ft_atoi(z_color[0]), ft_convert_color(z_color[1], "0123456789ABCDEF"));
		else
			map[y][x] = ft_create_point(x, y, ft_atoi(*z_color), 0);
		x++;
		free_split(z_color);
	}
}

t_point	***ft_build_map(int fd, char *map_file)
{
	char	*line;
	char	**split;
	t_point	***map;
	int		x;
	int		y;
	
	map = (t_point ***)malloc(calculate_matrix_y(map_file) * sizeof(t_point *));
	if (map == NULL)
		return (NULL);
	y = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		if (split == NULL) {
            free_matrix(map, y, 0);
            return NULL;
        }
		free(line);
		map[y] = (t_point **)malloc(calculate_matrix_x(map_file) * sizeof(t_point *));
		x = 0;
		create_rows(split, x, y, map);
		free_split(split);
		y++;
	}
	return (map);
}

int	exit_window(int keysym, t_vars_mlx *mlx_data)
{
	if (keysym == ESCAPE)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		exit(1);
	}
	return (0);
}

int main(int ac, char **av)
{
	int			map_fd;
	int			x;
	t_point		***map;
	t_vars_mlx	mlx_data;
	t_data		img;
	
	x = 0;
	mlx_data.mlx = mlx_init();
	if (mlx_data.mlx == NULL)
		return (1);
	mlx_data.win = mlx_new_window(mlx_data.mlx, HEIGHT, WIDTH, "fdf");

	img.img = mlx_new_image(mlx_data.mlx, HEIGHT, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	map_fd = open(av[ac - 1], O_RDONLY);
	map = ft_build_map(map_fd, av[ac - 1]);
	// show_matrix(calculate_matrix_y(av[ac - 1]), calculate_matrix_x(av[ac - 1]), map);
	free_matrix(map, calculate_matrix_y(av[ac - 1]), calculate_matrix_x(av[ac - 1]));

	while (x < 100)
	{
		ft_pixel_put(&img, x, x, 0x00FF0000);
		x++;
	}
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, img.img, 100, 200);
	mlx_key_hook(mlx_data.win, exit_window, &mlx_data);
	mlx_loop(mlx_data.mlx);
	
	close(map_fd);
}

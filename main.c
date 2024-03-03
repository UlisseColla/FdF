/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/03 19:58:31 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static int	exit_window(int keysym, t_vars_mlx *mlx_data)
{
	if (keysym == ESCAPE)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		mlx_destroy_display(mlx_data->mlx);
		free_matrix(mlx_data->map, mlx_data->matrix_y);
		free(mlx_data->mlx);
		exit(1);
	}
	return (0);
}

static int	mlx_data_init(t_vars_mlx *data, char *file)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "fdf");
	data->map_file = file;
	data->offset_x = 0;
	data->offset_y = 0;
	data->y_max = 0;
	data->y_min = 0;
	data->x_max = 0;
	data->x_min = 0;
	data->center_x = 0;
	data->center_y = 0;
	data->zoom = 1;
	return (0);
}

int main(int ac, char **av)
{
	int			map_fd;
	t_point		**map;
	t_vars_mlx	mlx_data;
	t_data		img;

	if (ac != 2)
		return (ft_error(1));
	if (check_map_extension(av[ac - 1], ".fdf") == 1)
		return (ft_error(42));
	if (mlx_data_init(&mlx_data, av[ac - 1]) == 1)
		return (1);
	map_fd = open(mlx_data.map_file, O_RDONLY);
	map = build_map(map_fd, mlx_data.map_file);
	mlx_data.map = map;
	mlx_data.matrix_y = calculate_y(mlx_data.map_file);
	// show_matrix(calculate_y(av[ac - 1]), map);
	put_grid(map, &img, mlx_data, calculate_y(mlx_data.map_file));
	// tmp_put_grid(map, &img, mlx_data, calculate_y(av[ac - 1]));
	
	mlx_key_hook(mlx_data.win, exit_window, &mlx_data);
	mlx_loop(mlx_data.mlx);
	close(map_fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/04 19:24:55 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static int	exit_window(t_vars_mlx *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	free_matrix(mlx_data->map, mlx_data->matrix_y);
	free(mlx_data->mlx);
	exit(1);
	return (0);
}

static int	mlx_data_init(t_vars_mlx *data, char *file)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH + MENU_WIDTH, HEIGHT, "fdf");
	data->map_file = file;
	data->offset_x = 0;
	data->offset_y = 0;
	data->y_max = 0;
	data->y_min = 0;
	data->x_max = 0;
	data->x_min = 0;
	data->center_x = 0;
	data->center_y = 0;
	data->matrix_y = calculate_y(data->map_file);
	data->zoom = 1;
	return (0);
}

int	key_hooks(int keysym, t_vars_mlx *data)
{
	if (keysym == ESCAPE)
		exit_window(data);
	if (keysym == UP || keysym == DOWN || keysym == RIGHT || keysym == LEFT)
		translate_hooks(keysym, data);
	return (0);
}

int main(int ac, char **av)
{
	int			map_fd;
	t_vars_mlx	mlx_data;

	if (ac != 2)
		return (ft_error(1));
	if (check_map_extension(av[ac - 1], ".fdf") == 1)
		return (ft_error(42));
	if (mlx_data_init(&mlx_data, av[ac - 1]) == 1)
		return (1);
	// mlx_data.img->img = mlx_new_image(mlx_data.mlx, HEIGHT, WIDTH);
	// mlx_data.img->addr = mlx_get_data_addr((mlx_data.img)->img, &(mlx_data.img->bits_per_pixel), &(mlx_data.img->line_length), &(mlx_data.img->endian));
	map_fd = open(mlx_data.map_file, O_RDONLY);
	mlx_data.map = build_map(map_fd, mlx_data.map_file);
	// show_matrix(calculate_y(av[ac - 1]), map);
	put_grid(mlx_data.map, mlx_data.img, mlx_data, mlx_data.matrix_y);
	print_menu(&mlx_data);
	mlx_hook(mlx_data.win, KeyPress, KeyPressMask, key_hooks, &mlx_data);
	mlx_loop(mlx_data.mlx);
	close(map_fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/08 13:13:41 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	exit_window(t_vars_mlx *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	free_matrix(mlx_data->map, mlx_data->matrix_y);
	free(mlx_data->mlx);
	exit(1);
	return (0);
}

void	img_init(t_data *img, t_vars_mlx *data)
{
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

int	mlx_data_init(t_vars_mlx *data, char *file)
{
	data->map_file = file;
	data->map_fd = open(data->map_file, O_RDONLY);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fdf");
	img_init(&(data->img), data);
	data->matrix_y = calculate_y(data->map_file);
	data->offset_x = 0;
	data->offset_y = 0;
	data->y_max = 0.00;
	data->y_min = 0.00;
	data->x_max = 0.00;
	data->x_min = 0.00;
	data->center_x = 0.00;
	data->center_y = 0.00;
	data->zoom = 1.00;
	data->zoom_0 = 1.00;
	data->angle_z = 30.00;
	data->zooming_factor = 0.85;
	return (0);
}

int	key_hooks(int keysym, t_vars_mlx *data)
{
	if (keysym == ESCAPE)
		exit_window(data);
	if (keysym == UP || keysym == DOWN || keysym == RIGHT || keysym == LEFT)
		translate_hooks(keysym, data);
	if (keysym == Z_UP || keysym == Z_DOWN)
		scale_hooks(keysym, data);
	if (keysym == ZOOM_IN || keysym == ZOOM_OUT)
		zoom_hooks(keysym, data);
	if (keysym == ROTATE_Z_LEFT || keysym == ROTATE_Z_RIGHT)
		rotate_z_hooks(keysym, data);
	// printf("key value: %d\n", keysym);
	// if (keysym == RESET)
	// 	reset_hook(data);
	return (0);
}

int main(int ac, char **av)
{
	t_vars_mlx	mlx_data;

	if (ac != 2)
		return (ft_error(1));
	if (check_map_extension(av[ac - 1], ".fdf") == 1)
		return (ft_error(42));
	if (mlx_data_init(&mlx_data, av[ac - 1]) == 1)
		return (1);
	mlx_data.map = build_map(&mlx_data);
	put_grid(&(mlx_data.img), &mlx_data);
	mlx_hook(mlx_data.win, KeyPress, KeyPressMask, key_hooks, &mlx_data);
	mlx_loop(mlx_data.mlx);
	close(mlx_data.map_fd);
	// print_menu(&mlx_data);
	// show_matrix(calculate_y(av[ac - 1]), map);
}

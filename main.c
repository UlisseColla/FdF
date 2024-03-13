/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/13 19:10:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	exit_window(t_vars_mlx *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img.img); //controllare puntatori
	mlx_destroy_image(mlx_data->mlx, mlx_data->menu_img.img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_window(mlx_data->mlx, mlx_data->menu_win);
	mlx_destroy_display(mlx_data->mlx);
	free_matrix(mlx_data->map, mlx_data->matrix_y);
	free(mlx_data->map_name);
	free(mlx_data->total_points);
	free(mlx_data->mlx);
	exit(1);
}

int	img_init(t_data *img, t_data *menu_img, t_vars_mlx *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->map_name);
	data->menu_win = mlx_new_window(data->mlx, MENU_W, MENU_H, "menu");
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	menu_img->img = mlx_new_image(data->mlx, MENU_W, MENU_H);
	menu_img->addr = mlx_get_data_addr(menu_img->img, &menu_img->bits_per_pixel,
			&menu_img->line_length, &menu_img->endian);
	return (0);
}

int	mlx_data_init(t_vars_mlx *data, char *file)
{
	data->map_file = file;
	data->map_name = get_map_name(data);
	data->map_fd = open(data->map_file, O_RDONLY);
	data->map = NULL;
	if (img_init(&(data->img), &(data->menu_img), data) == 1)
		return (1);
	data->has_color = 0;
	data->matrix_y = calculate_y(data->map_file);
	data->total_points = 0;
	data->z_min = 0;
	data->z_max = 0;
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
	data->zooming_factor = 0.851;
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
	if (keysym == RESET)
		reset_hook(data);
	if (keysym == PARALLEL)
		parallel_hook(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars_mlx	mlx_data;

	if (ac != 2)
		return (ft_error(&mlx_data, 1));
	if (check_map_extension(av[ac - 1], ".fdf") == 1)
		return (ft_error(&mlx_data, 2));
	if (mlx_data_init(&mlx_data, av[ac - 1]) == 1)
		return (1);
	build_map(&mlx_data);
	max_and_min_Z(&mlx_data, 0, 0);
	if (check_map_size(&mlx_data) == 1)
		return (ft_error(&mlx_data, 3));
	if (mlx_data.has_color == 0)
		define_colors(&mlx_data, 0, 0);
	put_grid(&(mlx_data.img), &mlx_data);
	print_menu(&mlx_data, 1);
	mlx_hook(mlx_data.win, KeyPress, KeyPressMask, key_hooks, &mlx_data);
	mlx_loop(mlx_data.mlx);
	close(mlx_data.map_fd);
}

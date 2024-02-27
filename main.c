/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/27 18:03:27 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map_extension(char *file, char *extension)
{
	int	i;
	int	j;

	i = ft_strlen(file);
	j = ft_strlen(extension);
	while (i >= 0 && j >= 0)
	{
		if (file[i] == '.' && extension[j] == '.')
			return (0);
		if (file[i] == extension[j])
			j--;
		else
			break ;
		i--;
	}
	return (1);
}

int	ft_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("Not enough parameters\n", 1);
	else
		ft_putstr_fd("Wrong file extension. Map files must end with .fdf\n", 1);
	return (1);
}

int	exit_window(int keysym, t_vars_mlx *mlx_data)
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
	mlx_data.mlx = mlx_init();
	if (mlx_data.mlx == NULL)
		return (1);
	mlx_data.win = mlx_new_window(mlx_data.mlx, HEIGHT, WIDTH, "fdf");
	mlx_data.map_file = av[ac - 1];
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:04:53 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/13 16:11:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_map_size(t_vars_mlx *data)
{
	t_point	**map;
	int		x;
	int		y;
	int		checker;

	map = data->map;
	y = 0;
	checker = 0;
	while (y < data->matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			x++;
			if (y == 0)
				checker++;
		}
		if (x != checker)
			return (1);
		y++;
	}
	data->total_points = ft_itoa(checker * y);
	return (0);
}

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

int	ft_error(t_vars_mlx *data, int flag)
{
	if (flag == 1)
		ft_putstr_fd("Not enough parameters\n", 1);
	else if (flag == 2)
		ft_putstr_fd("Wrong file extension. Map files must end with .fdf\n", 1);
	else
	{
		exit_window(data);
		ft_putstr_fd("Wrong map size. Not all rows are the same size\n", 1);
	}
	return (1);
}

void	free_matrix(t_point **matrix, int matrix_y)
{
	int i;

	i = 0;
	while (i < matrix_y)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

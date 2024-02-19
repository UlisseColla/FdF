/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:47:55 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/19 16:07:41 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_convert_color(const char *str, char *str_base)
{
    int i;
    int j;
    int result;

    i = 0;
    result = 0;
	if (ft_strncmp(&str[i], "0x", 2) == 0)
		i += 2;
    while (str[i])
    {
        j = 0;
        while (str_base[j] && str[i] != str_base[j])
            j++;
        if (str_base[j])
            result = result * ft_strlen(str_base) + j;
        else
            break ;
        i++;
    }
    return (result);
}

int	calculate_matrix_y(char *map)
{
	int		map_fd;
	int		count;
	char	*line;

	map_fd = open(map, O_RDONLY);
	count = 0;
	while (42)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	close(map_fd);
	return (count);
}

int	calculate_matrix_x(char *map)
{
	int		map_fd;
	int		count;
	char	**split;
	char	*line;
	
	map_fd = open(map, O_RDONLY);
	count = 0;
	line = get_next_line(map_fd);
	split = ft_split(line, ' ');
	while (split[count])
		count++;
	free_split(split);
	free(line);
	close (map_fd);
	return (count);
}

int	split_len(char **split)
{
	int i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

void	show_matrix(int matrix_y, int matrix_x, t_point ***map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < matrix_y)
	{
		x = 0;
		while (x < matrix_x)
		{
			printf("{x-%d y-%d z-%d} \n", map[y][x]->x, map[y][x]->y, map[y][x]->z);
			x++;
		}
		y++;
	}
}

void	free_matrix(t_point ***matrix, int matrix_y, int matrix_x)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < matrix_y)
	{
		j = 0;
		while (j < matrix_x)
		{
			free(matrix[i][j]);
			matrix[i][j] = NULL;
			j++;
		}
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

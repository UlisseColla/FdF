/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:47:55 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/01 14:38:09 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int	split_len(char **split)
{
	int i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

void	show_matrix(int matrix_y, t_point **map)
{
	int x;
	int y;

	y = 0;
	while (y < matrix_y)
	{
		x = 0;
		while (map[y][x].color != -1)
		{
			printf("{x-%f y-%f color-%d} \n", map[y][x].x, map[y][x].y, map[y][x].color);
			x++;
		}
		printf("\n");
		y++;
	}
}
int	calculate_y(char *map_file)
{
	int	fd;
	int	i;
	char buff;
	ssize_t n_read;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1) {
        perror("Error opening file");
        return -1;
    }
	n_read = read(fd, &buff, 1);
	while (n_read > 0)
	{
		if (buff == '\n')
			i++;
		n_read = read(fd, &buff, 1);
	}
	if (n_read == -1) {
        perror("Error reading file");
        close(fd);
        return -1;
    }
	close(fd);
	return (i + 1);
}

int	calculate_x(t_point **map)
{
	int	x;

	x = 0;
	while (map[0][x].color != -1)
		x++;
	return (x);
}

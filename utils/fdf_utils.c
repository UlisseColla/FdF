/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:47:55 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/11 17:39:23 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	split_len(char **split)
{
	int i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
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

unsigned long int	convert_color(const char *str)
{
	int					i;
	unsigned long int	value;
	int					c;

	value = 0;
	i = 0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
	{
		i += 2;
	}
	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= '0' && c <= '9')
			value = value * 16 + (c - '0');
		else if (c >= 'a' && c <= 'f')
			value = value * 16 + (c - 'a' + 10);
		else if (c >= 'A' && c <= 'F')
			value = value * 16 + (c - 'A' + 10);
		else
			break ;
		i++;
	}
	return (value);
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
			printf("{color-> %X} \n", map[y][x].color);
			x++;
		}
		printf("\n");
		y++;
	}
}
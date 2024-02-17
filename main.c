/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulissecolla <ulissecolla@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/17 17:17:41 by ulissecolla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_create_point(int x, int y, int z, int color)
{
	t_point	new;

	printf("creat_point\n");
	new = *(t_point *)malloc(sizeof(t_point));
	new.x = x;
	new.y = y;
	new.z = z;
	new.color = color;
	new.right = NULL;
	new.down = NULL;
	return (new);
}

int	calculate_matrix_y(char *map)
{
	int		map_fd;
	int		count;

	map_fd = open(map, O_RDONLY);
	count = 0;
	while (get_next_line(map_fd))
		count++;
	close(map_fd);
	return (count);
}

int	calculate_matrix_x(char *map)
{
	int		map_fd;
	int		count;
	char	**line;

	map_fd = open(map, O_RDONLY);
	count = 0;
	line = ft_split(get_next_line(map_fd), ' ');
	while (line[count])
		count++;
	while (*line)
	{
		free(*line);
		line++;
	}
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

t_point	**ft_build_map(int fd, char *map_file)
{
	char	*line;
	char	**split;
	char	**z_color;
	t_point	**map;
	int		x;
	int		y;
	
	map = (t_point **)malloc(calculate_matrix_y(map_file) * sizeof(t_point));
	y = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		x = 0;
		while (split[x] != NULL)
		{
			z_color = ft_split(split[x], ',');
			printf("z_color: %s\n", *z_color);
			if (split_len(z_color) > 1)
			{
				printf("if !-!-!\n");	
				map[y][x] = ft_create_point(x, y, ft_atoi(z_color[0]), ft_atoi_base(z_color[1], "0123456789ABCDEF"));
			}
			else
			{
				printf("else !-!-!\n");
				map[y][x] = ft_create_point(x, y, ft_atoi(*z_color), 0);
			}
			x++;
			printf("Nuovo punto: %d\n", map[y][x].z);
		}
		y++;
	}
	return (map);
}

int main(int ac, char **av)
{
	int		map_fd;
	t_point	**map;
	/* char *line; */
	int y, x;
	
	map_fd = open(av[ac - 1], O_RDONLY);
	map = ft_build_map(map_fd, av[ac - 1]);
	printf("!--!\n");
	y = 0;
	printf("ok\n");
	while (y < calculate_matrix_y(av[ac - 1]))
	{
		x = 0;
		while (x < calculate_matrix_x(av[ac - 1]))
		{
			printf("%d ", map[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
	(void)map;
}
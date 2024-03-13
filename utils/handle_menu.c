/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:13:43 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/13 18:47:58 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*get_map_name(t_vars_mlx *data)
{
	char	*name;
	size_t	i;
	int		j;

	i = ft_strlen(data->map_file);
	while (i >= 0)
	{
		if (data->map_file[i] == '/')
			break ;
		i--;
	}
	name = ft_calloc(ft_strlen(data->map_file) - 3 - i, sizeof(char));
	j = 0;
	i++;
	while (data->map_file[i] && i < ft_strlen(data->map_file) - 4)
	{
		name[j] = data->map_file[i];
		i++;
		j++;
	}
	name[j] = '\0';
	return (name);
}

void	menu_controls(t_vars_mlx *data, int c)
{
	int		y;
	void	*m;
	void	*w;

	y = 50;
	m = data->mlx;
	w = data->menu_win;
	mlx_string_put(m, w, 50, y, c, "CONTROLS ----------------- KEYS");
	mlx_string_put(m, w, 50, y += 25, c, "Quit the program           -> ESC ");
	mlx_string_put(m, w, 50, y += 25, c, "Reset the image            -> R ");
	mlx_string_put(m, w, 50, y += 25, c, "Parallel projection        -> P ");
	mlx_string_put(m, w, 50, y += 25, c, "Translate the image:");
	mlx_string_put(m, w, 50, y += 18, c, "* Right                    -> D ");
	mlx_string_put(m, w, 50, y += 18, c, "* Left                     -> A ");
	mlx_string_put(m, w, 50, y += 18, c, "* Up                       -> W ");
	mlx_string_put(m, w, 50, y += 18, c, "* Down                     -> S ");
	mlx_string_put(m, w, 50, y += 25, c, "Change the Z value:");
	mlx_string_put(m, w, 50, y += 18, c, "* Scale up                 -> O ");
	mlx_string_put(m, w, 50, y += 18, c, "* Scale down               -> I ");
	mlx_string_put(m, w, 50, y += 25, c, "Zoom:");
	mlx_string_put(m, w, 50, y += 18, c, "* Zoom in                  -> + ");
	mlx_string_put(m, w, 50, y += 18, c, "* Zoom out                 -> - ");
}

void	map_info(t_vars_mlx *data, int c)
{
	int		y;
	void	*m;
	void	*w;
	char	*str;

	y = 400;
	m = data->mlx;
	w = data->menu_win;
	mlx_string_put(m, w, 50, y, c, "---------- MAP INFO ----------");
	mlx_string_put(m, w, 50, y += 25, c, "Map name:");
	mlx_string_put(m, w, 50, y += 18, c, "* ");
	mlx_string_put(m, w, 60, y, c, data->map_name);
	mlx_string_put(m, w, 50, y += 25, c, "Total number of points:");
	mlx_string_put(m, w, 50, y += 18, c, "* ");
	mlx_string_put(m, w, 60, y, c, data->total_points);
	mlx_string_put(m, w, 50, y += 25, c, "Zooming factor: ");
	mlx_string_put(m, w, 50, y += 18, c, "* ");
	str = convert_zoom(data->zooming_factor);
	mlx_string_put(m, w, 60, y, c, str);
	free(str);
}

void	map_info_2(t_vars_mlx *data, int c, int flag)
{
	int		y;
	void	*m;
	void	*w;
	char	*str;

	y = 529;
	m = data->mlx;
	w = data->menu_win;
	mlx_string_put(m, w, 50, y += 25, c, "Highest and lowest z values: ");
	mlx_string_put(m, w, 50, y += 18, c, "* ");
	str = ft_itoa(data->z_max);
	mlx_string_put(m, w, 60, y, c, str);
	free(str);
	mlx_string_put(m, w, 50, y += 18, c, "* ");
	str = ft_itoa(data->z_min);
	mlx_string_put(m, w, 60, y, c, str);
	free(str);
	mlx_string_put(m, w, 50, y+= 25, c, "Projection:");
	mlx_string_put(m, w, 50, y += 18, c, "* ");
	if (flag == 1)
		mlx_string_put(m, w, 60, y, c, "Isometric");
	else
		mlx_string_put(m, w, 60, y, c, "Parallel");
	mlx_string_put(m, w, 50, y+= 25, c, "<<<------------------------>>>");
}

void	print_menu(t_vars_mlx *data, int flag)
{
	int	x;
	int	y;

	y = 0;
	while (y < MENU_H)
	{
		x = 0;
		while (x < MENU_W)
		{
			ft_pixel_put(&(data->menu_img), x, y, 0x111111); //0x0040FF
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->menu_win,
		data->menu_img.img, 0, 0);
	menu_controls(data, 0xFFFF00);
	map_info(data, 0xFFFFFF);
	map_info_2(data, 0xFFFFFF, flag);
}

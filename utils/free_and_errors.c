/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:04:53 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/01 14:38:12 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

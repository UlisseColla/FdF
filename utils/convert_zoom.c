/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:19:36 by ucolla            #+#    #+#             */
/*   Updated: 2024/03/13 18:48:59 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*convert_zoom(float n)
{
	char	*n1;
	char	n2[5];
	char	*str;
	float	tmp;
	int		i;

	n1 = ft_itoa((int)n);
	tmp = n - (int)n;
	i = 1;
	n2[0] = '.';
	n2[4] = '\0';
	while (i < 4)
	{
		tmp *= 10;
		n2[i] = ((int)tmp % 10) + 48;
		i++;
	}
	str = ft_strjoin(n1, n2);
	free(n1);
	return (str);
}

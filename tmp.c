/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulissecolla <ulissecolla@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:30:35 by ulissecolla       #+#    #+#             */
/*   Updated: 2024/02/17 16:31:08 by ulissecolla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_add_point_back(t_point **map, t_point *new)
{
	t_point	*tmp;

	if (*map == NULL)
	{
		*map = new;
		return ;
	}
	tmp = *map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	tmp->right = new;
}
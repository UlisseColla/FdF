/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulissecolla <ulissecolla@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:57:33 by ulissecolla       #+#    #+#             */
/*   Updated: 2024/02/17 15:02:44 by ulissecolla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi_base(const char *str, char *str_base)
{
    int i;
    int j;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
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
    return (result * sign);
}

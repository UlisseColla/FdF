/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:24 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/06 16:02:44 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (void *)malloc((nmemb * size));
	if (ptr == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, size_t k)
{
	char	*ret;
	size_t	a;
	size_t	b;

	ret = (char *)ft_calloc_gnl(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1,
			sizeof(char));
	a = 0;
	b = 0;
	while (s1 && s1[a] != '\0')
	{
		ret[a] = s1[a];
		a++;
	}
	while (s2 && s2[b] != '\0' && b < k)
	{
		ret[a] = s2[b];
		a++;
		b++;
	}
	ret[a] = '\0';
	free(s1);
	return (ret);
}

char	*ft_strchr_gnl(char *str, char a)
{
	while (*str != a && *str)
		str++;
	if (!*str)
		return (NULL);
	return (str + 1);
}

char	*ft_strdup_gnl(char *str)
{
	char	*copy;
	size_t	k;

	copy = (char *)ft_calloc_gnl(ft_strlen_gnl(str) + 1, sizeof(char));
	k = 0;
	while (str[k] != '\0')
	{
		copy[k] = str[k];
		k++;
	}
	copy[k] = '\0';
	return (copy);
}

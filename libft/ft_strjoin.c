/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:47:48 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/05 16:39:09 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fn_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (i < size && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(dst));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	fn_strlcpy(str, s1, ft_strlen(s1));
	fn_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (str);
}

/*int main()
{
	char *str1 = "Hello ";
	char *str2 = "World!";
	char *ret = ft_strjoin(str1, str2);
	printf("%s\n", ret);
	return (0);
}*/

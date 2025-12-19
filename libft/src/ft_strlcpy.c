/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:48:18 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/14 11:54:50 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!dst || !src)
		return (0);
	s_len = ft_strlen(src);
	if (siz == 0)
		return (s_len);
	while (*src && i++ < siz - 1)
		*dst++ = *src++;
	*dst = 0;
	return (s_len);
}

// #include <stdio.h>
// int main()
// {
// 	char *str = "lorem ipsum dolor sit amet";
// 	char dest[20];
// 	printf("%zu\n", ft_strlcpy(dest, str, 0));
// 	printf("%s", dest);
// }

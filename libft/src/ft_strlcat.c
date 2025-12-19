/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:09:20 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/16 14:34:29 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (siz <= dest_len || siz == 0)
		return (src_len + siz);
	i = 0;
	while (src[i] && (dest_len + i) < siz - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = 0;
	return (dest_len + src_len);
}

// #include <stdio.h>
// int main()
// {
// 	// char *src = "CDE";
// 	char det[] = "Hello";
// 	printf("%zu\n", ft_strlcat(det, " world", 15));
// 	printf("%s", det);
// }
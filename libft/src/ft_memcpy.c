/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:14:20 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/01 12:53:48 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*dst++ = *s++;
	return (dest);
}

// #include <stdio.h>
// int main ()
// {
// 	char str[] = "Hello world";
// 	printf("%s\n", str);
// 	ft_memcpy(str + 3, str, 8);
// 	printf("%s", str);
// 	return (0);
// }
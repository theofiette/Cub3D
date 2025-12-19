/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:26:33 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/29 14:44:12 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*dst;

	dst = (unsigned char *)dest;
	s1 = (unsigned char *)src;
	if (dest < src)
		while (n--)
			*dst++ = *s1++;
	else if (dest > src)
		while (n--)
			*(dst + n) = *(s1 + n);
	return ((unsigned char *)dest);
}

// #include <stdio.h>
// int main ()
// {
// 	char str[] = "Hello world";
// 	ft_memmove(str + 3, str, 2);
// 	printf("dest < src : src - 2 = %s \n", str + 3);
// 	printf("dest < src : src = %s \n\n", str);

// 	char str2[] = "0123456789";
// 	ft_memmove(str2 + 2, str2, 2);
// 	printf("dest > src2 : src2 + 4 = %s\n", str2 + 2);
// 	printf("src2 =  %s", str2);
// 	return (0);
// }
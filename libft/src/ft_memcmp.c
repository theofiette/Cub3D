/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:03:23 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/29 15:19:06 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1 && s2) && (*(unsigned char *)s1 == *(unsigned char *)s2)
		&& i++ < (n - 1))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// #include <stdio.h>
// int main ()
// {
// 	char s1[] = "Hello world";
// 	char s2[] = "Hello world";
// 	printf("%d", ft_memcmp(s1, s2, 5));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:37:37 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/01 12:43:08 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cc = (unsigned char )c;
	s1 = (unsigned char *)s;
	while (n--)
	{
		if (*s1 == cc)
			return (s1);
		s1++;
	}
	return (0);
}

// #include <stdio.h>
// int main ()
// {
// 	char str[] = "Hello world";
// 	printf("%s \n", str);
// 	printf("%s", (char *)ft_memchr(str, 'r', 50));
// 	return (0);
// }
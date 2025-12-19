/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:17:30 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/28 13:58:14 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
		*s1++ = (unsigned char)c;
	return (s);
}

// #include <stdio.h>
// int main ()
// {
// 	char str[] = "Hello world";
// 	int	tab[] = {1, 2, 3};
// 	printf("%s \n", str);
// 	ft_memset(str, -40, 3);
// 	// memset(str, 'a', 10);
// 	printf("%s\n", str);
// 	ft_memset(tab, 0, 12);
// 	// memset(tab, 0, 12); 
// 	int i = 0;
// 	while (i < 3)
// 		printf("%d\n",tab[i++]);
// 	return (0);
// }
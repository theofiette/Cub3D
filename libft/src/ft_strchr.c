/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:58:56 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/01 11:42:32 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_strchr("Hello", '\0') + 1);
// 	printf("real : %s\n", strchr("Hello", '\0'));
// 	printf("%s\n", ft_strchr("World", 'r'));
// 	printf("%s\n", ft_strchr("Hi",'k'));
// 	printf("real = %s\n", strchr("Hi",'k'));
// 	printf("%s\n", ft_strchr("lol", 'o'));
// 	printf("%s\n", ft_strchr("0123456789", '0'));
// 	return (0);
// }
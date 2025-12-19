/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:48:59 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/01 11:51:57 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;

	size = 0;
	if ((char)c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	size = ft_strlen(s);
	while (size--)
		if (s[size] == (char)c)
			return ((char *)(s + size));
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s\n", ft_strrchr("Hello", 'H'));
// 	printf("%s\n", ft_strrchr("Worldr", 'o'));
// 	printf("%s\n", ft_strrchr("Hi",'k'));
// 	printf("%s\n", ft_strrchr("looooolooolool", 'l'));
// 	printf("%s\n", ft_strrchr("01234506789", '0'));
// 	return (0);
// }
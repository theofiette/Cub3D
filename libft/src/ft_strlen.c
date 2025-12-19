/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:36:16 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/12 15:22:59 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%zu\n", ft_strlen(0));
// 	printf("%zu\n", ft_strlen("World"));
// 	printf("%zu\n", ft_strlen("Hi"));
// 	printf("%zu\n", ft_strlen("lol"));
// 	printf("%zu\n", ft_strlen("0123456789"));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:22:28 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/28 11:31:18 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*start;

	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (0);
	start = str;
	while (s && *s)
		*str++ = *s++;
	*str = 0;
	return (start);
}

// #include <stdio.h>
// int main ()
// {
// 	char *str = "Hello world";
// 	char *dest = ft_strdup(str);
// 	printf("%s", dest);
// }
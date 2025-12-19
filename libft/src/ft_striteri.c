/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:01:40 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/27 21:58:39 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	ft_even_upper(unsigned int n, char *c)
// {
// 	if (n % 2 == 0 && (*c > 96 && *c < 123))
// 		*c -= 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
		f(i++, s++);
}

// #include <stdio.h>
// int main ()
// {
// 	char str[] = "Hello World";

// 	ft_striteri(str, &ft_even_upper);
// 	printf("%s", str);
// 	return (0);
// }
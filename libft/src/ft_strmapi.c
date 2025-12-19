/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:29:12 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/28 15:49:52 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	ft_even_upper(unsigned int n, char c)
// {
// 	if (n % 2 == 0 && (c > 96 && c < 123))
// 		c -= 32;
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			slen;
	char			*new_str;
	unsigned int	i;

	slen = ft_strlen(s);
	new_str = malloc(1 + slen * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (s && *s)
		*new_str++ = f(i++, *s++);
	*new_str = 0;
	return (new_str - slen);
}

// #include <stdio.h>
// int main ()
// {
// 	char *str = "hello world";
// 	char *modif;

// 	modif = ft_strmapi(str, ft_even_upper);
// 	printf("%s", modif);
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:50:12 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/01 12:14:55 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*sstart;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
	{
		str = malloc(1);
		if (!str)
			return (0);
		return (str[0] = 0, str);
	}
	if (len > slen - start)
		len = slen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	sstart = str;
	while ((s && *(s + start) && len--))
		*str++ = *(s + start++);
	*str = 0;
	return (sstart);
}

// int main ()
// {
// 	char *str = "Hello world";
// 	char *dest = ft_substr(str, 2, 8);
// 	printf("%s",dest);
// 	return (0);
// }
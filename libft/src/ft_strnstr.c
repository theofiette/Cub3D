/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:52:12 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/01 13:08:24 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j]
			&& (i + j) < len && little[j] == big[i + j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main()
// {
// 	char *little = "ipsum";
// 	char *big = "lorem ipsum dolor sit amet";

// 	printf("%s",ft_strnstr(big, little, 11));
// 	printf("%s",strnstr(big, little, 15));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:50:42 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/26 15:17:31 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%c\n", ft_tolower(65));
// 	printf("%c\n", ft_tolower(42));
// 	printf("%c\n", ft_tolower(121));
// 	printf("%c\n", ft_tolower(84));
// 	printf("%c\n", ft_tolower(75));
// 	return (0);
// }
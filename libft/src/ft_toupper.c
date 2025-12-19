/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:45:15 by tchevall          #+#    #+#             */
/*   Updated: 2025/04/26 15:17:26 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%c\n", ft_toupper(95));
// 	printf("%c\n", ft_toupper(75));
// 	printf("%c\n", ft_toupper(55));
// 	printf("%c\n", ft_toupper(121));
// 	printf("%c\n", ft_toupper(110));
// 	return (0);
// }
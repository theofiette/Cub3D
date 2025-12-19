/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:23:14 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/18 14:25:14 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size += 1;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*num;
	long	nb;

	nb = n;
	size = intlen(nb);
	num = malloc(1 + size * sizeof(char));
	if (!num)
		return (0);
	*(num + size) = 0;
	*num = '0';
	if (n < 0)
	{
		nb = -nb;
		*num = '-';
	}
	while (nb && size--)
	{
		*(num + size) = nb % 10 + 48;
		nb /= 10;
	}
	return (num);
}

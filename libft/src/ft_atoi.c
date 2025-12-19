/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:54:31 by tchevall          #+#    #+#             */
/*   Updated: 2025/11/10 19:55:22 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		res;
	int		sign;
	char	*num;

	num = (char *)nptr;
	sign = 1;
	while ((*num >= 9 && *num <= 13) || *num == 32)
		num++;
	if (*num == '+' || *num == '-')
	{
		if (*num == '-')
			sign = -sign;
		num++;
		if (*num == '+' || *num == '-')
			return (0);
	}
	res = 0;
	while (*num >= '0' && *num <= '9')
	{
		res = res * 10 + *num - 48;
		num++;
	}
	return (res * sign);
}

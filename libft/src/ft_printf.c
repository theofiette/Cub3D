/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:36:33 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/18 13:28:39 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count_ret;

	if (!str)
		return (-1);
	if (str[0] == '%' && !str[1])
		return (-1);
	va_start(list, str);
	count_ret = 0;
	count_ret += ft_readpercent(str, list);
	va_end(list);
	return (count_ret);
}

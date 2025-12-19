/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readpercent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:37:15 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/18 13:27:50 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_format(char c)
{
	char	*format;

	format = "cspdiuxX%";
	while (*format)
	{
		if (c == *format)
			return (1);
		format++;
	}
	return (0);
}

int	ft_putchar(char c)
{
	int	count;

	count = 1;
	write(1, &c, 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		ft_putstr("(null)");
		count = 6;
	}
	while (str && *str)
	{
		ft_putchar(*str++);
		count++;
	}
	return (count);
}

int	write_percent(const char *str, va_list list)
{
	int	count_c;

	count_c = 0;
	if (*str == 'd' || *str == 'i')
		count_c += ft_putnbr(va_arg(list, int));
	else if (*str == 's')
		count_c += ft_putstr(va_arg(list, char *));
	else if (*str == 'u')
		count_c += ft_putunbr(va_arg(list, unsigned));
	else if (*str == 'c')
		count_c += ft_putchar(va_arg(list, int));
	else if (*str == '%' || !is_format(*str))
		count_c += ft_putchar('%');
	else if (*str == 'p')
		count_c += ft_printadress(va_arg(list, unsigned long long));
	else if (*str == 'x')
		count_c += ft_putnbr_base(va_arg(list, unsigned), "0123456789abcdef");
	else if (*str == 'X')
		count_c += ft_putnbr_base(va_arg(list, unsigned), "0123456789ABCDEF");
	return (count_c);
}

int	ft_readpercent(const char *str, va_list list)
{
	int	count_c;

	count_c = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count_c += write_percent(str, list);
		}
		else
			count_c += ft_putchar(*str);
		str++;
	}
	return (count_c);
}

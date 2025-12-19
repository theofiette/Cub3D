/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevall <tchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:14:23 by tchevall          #+#    #+#             */
/*   Updated: 2025/05/18 13:28:44 by tchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned int str_addr, char *base)
{
	int					count;
	unsigned int		addr;

	count = 0;
	addr = (unsigned int )str_addr;
	if (addr > 15)
		count += ft_putnbr_base(addr / 16, base);
	count++;
	ft_putchar(base[addr % 16]);
	return (count);
}

int	ft_putnbr_base_adrr(unsigned long long str)
{
	int					count;
	char				*base;

	count = 0;
	base = "0123456789abcdef";
	if (str > 15)
		count += ft_putnbr_base_adrr(str / 16);
	count++;
	ft_putchar(base[str % 16]);
	return (count);
}

int	ft_printadress(unsigned long long str)
{
	int	count;

	count = 0;
	if (str == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_base_adrr(str);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		count += 1;
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count++;
	ft_putchar(n % 10 + 48);
	return (count);
}

int	ft_putunbr(int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	nb = n;
	if (nb > 9)
		count += ft_putunbr(nb / 10);
	count += 1;
	ft_putchar(nb % 10 + 48);
	return (count);
}

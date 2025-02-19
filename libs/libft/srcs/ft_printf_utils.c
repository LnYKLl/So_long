/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:36:31 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/23 05:48:29 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

size_t	ft_putnbr(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		i++;
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	return (i);
}

int	ft_address(unsigned long n, int addprefix, int count)
{
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (addprefix)
		count += ft_putstr("0x");
	if (n == 0)
		count += ft_putchar('0');
	else
	{
		if (n >= 16)
			count += ft_address(n / 16, 0, count);
		count += ft_putchar(base[n % 16]);
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putnbr_unsigned(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

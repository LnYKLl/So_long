/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:12:21 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/23 05:48:33 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(char c, va_list args)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += ft_putchar((char)va_arg(args, int));
	if (c == 's')
		j += ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		j += ft_putnbr(va_arg(args, int));
	if (c == '%')
		j += ft_putchar('%');
	if (c == 'p')
		j += ft_address(va_arg(args, unsigned long), 1, j);
	if (c == 'x')
		j += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	if (c == 'X')
		j += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	if (c == 'u')
		j += ft_putnbr_unsigned(va_arg(args, unsigned int));
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j += ft_format(format[i], args);
		}
		else
			j += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (j);
}

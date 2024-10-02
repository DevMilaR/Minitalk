/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzmilaromano <luzmilaromano@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:58:44 by lromano           #+#    #+#             */
/*   Updated: 2024/10/02 23:03:04 by luzmilaroma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkprint(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count = ft_signed_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_putnbr(va_arg(args, unsigned int), DEC);
	else if (c == 'x')
		count = ft_putnbr(va_arg(args, unsigned int), HEX_LOWER);
	else if (c == 'X')
		count = ft_putnbr(va_arg(args, unsigned int), HEX_UPPER);
	else if (c == 'p')
	{
		count = ft_putstr("0x");
		count += ft_putnbr((unsigned long)va_arg(args, void *), HEX_LOWER);
	}
	else if (c == '%')
		count = ft_putchar('%');
	else
		count = write(1, &c, 1);
	return (count);
}

int	ft_printf(char const *fmt, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			len += ft_checkprint(args, *(++fmt));
		else
			len += ft_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	return (len);
}

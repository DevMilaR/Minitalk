/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzmilaromano <luzmilaromano@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:49:41 by lromano           #+#    #+#             */
/*   Updated: 2024/04/24 09:57:56 by luzmilaroma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned long n, char *base)
{
	size_t	base_len;
	int		len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	len = 0;
	if (n >= base_len)
		len += ft_putnbr(n / base_len, base);
	len += ft_putchar(base[n % base_len]);
	return (len);
}

int	ft_signed_putnbr(long n)
{
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n, DEC));
	else
		return (ft_putnbr(n, DEC));
}

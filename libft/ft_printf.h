/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzmilaromano <luzmilaromano@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:57:05 by lromano           #+#    #+#             */
/*   Updated: 2024/04/24 09:57:50 by luzmilaroma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define DEC "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printf(char const *fmt, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(unsigned long n, char *base);
int		ft_signed_putnbr(long n);

#endif
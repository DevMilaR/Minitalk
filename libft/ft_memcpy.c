/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzmilaromano <luzmilaromano@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:35:33 by lromano           #+#    #+#             */
/*   Updated: 2024/10/02 21:48:12 by luzmilaroma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*scr_ptr;

	i = 0;
	dest_ptr = dst;
	scr_ptr = src;
	if (dest_ptr == NULL && scr_ptr == NULL)
		return (NULL);
	while (i < n)
	{
		*(dest_ptr + i++) = *(scr_ptr++);
	}
	return (dst);
}

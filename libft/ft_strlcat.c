/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzmilaromano <luzmilaromano@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:02:59 by lromano           #+#    #+#             */
/*   Updated: 2024/10/02 21:51:14 by luzmilaroma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_index;
	size_t	src_index;

	dst_index = 0;
	src_index = 0;
	while (dst_index < dstsize && dst[dst_index])
	{
		dst_index++;
	}
	while ((dst_index + src_index + 1) < dstsize && src[src_index])
	{
		dst[dst_index + src_index] = src[src_index];
		src_index++;
	}
	if (dst_index != dstsize)
	{
		dst[dst_index + src_index] = '\0';
	}
	return (dst_index + ft_strlen(src));
}

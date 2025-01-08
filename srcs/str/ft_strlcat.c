/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:25:11 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:20:43 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	i;

	dst_size = 0;
	i = 0;
	while (dst[dst_size] && dst_size < size)
		dst_size++;
	if (size == 0 || dst_size == size)
		return (dst_size + ft_strlen(src));
	while (src[i] && i < size - dst_size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = 0;
	return (dst_size + ft_strlen(src));
}

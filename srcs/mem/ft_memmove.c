/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:33:50 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:14:22 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;
	int	delta;

	delta = src - dest;
	if (delta < (int)n && delta > 0)
	{
		i = 0;
		while (i < (int)n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (dest);
	}
	else if (dest == src)
		return (dest);
	else
		return (ft_memcpy(dest, src, n));
}

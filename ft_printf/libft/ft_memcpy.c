/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:05:11 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/08 11:34:38 by lcesbron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (src == NULL && dest == NULL)
		return (NULL);
	while (n)
	{
		((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
		n--;
	}
	return (dest);
}

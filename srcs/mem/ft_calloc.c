/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:24:39 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:13:57 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	bytes;

	bytes = nmemb * size;
	if ((size && nmemb > (SIZE_MAX / size))
		|| (nmemb && size > (SIZE_MAX / nmemb))
		|| bytes > 2147483648)
		return (NULL);
	ret = malloc(bytes);
	if (!ret)
		return (NULL);
	ft_bzero(ret, bytes);
	return (ret);
}

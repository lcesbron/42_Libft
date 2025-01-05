/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:24:39 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/18 19:21:38 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	bytes;

	if (size && nmemb > (SIZE_MAX / size))
		return (NULL);
	bytes = nmemb * size;
	ret = malloc(bytes);
	if (!ret)
		return (NULL);
	ft_bzero(ret, bytes);
	return (ret);
}

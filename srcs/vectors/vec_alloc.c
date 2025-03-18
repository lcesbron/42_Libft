/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:08:15 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/17 17:23:10 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"
#include "vectors.h"
#include <stdlib.h>

char	vec_alloc(t_vec *vec)
{
	void	*buffer;

	if (!vec->alloc)
		vec->alloc = VEC_SIZE;
	else
		vec->alloc <<= 1;
	buffer = malloc(vec->alloc * vec->el_size);
	if (!buffer)
		return (1);
	ft_memmove(buffer, vec->data, vec->size * vec->el_size);
	free(vec->data);
	vec->data = buffer;
	return (0);
}

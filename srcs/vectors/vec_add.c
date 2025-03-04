/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:29:06 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/04 13:21:53 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "mem.h" 

char	vec_add(t_vec *vec, void *el)
{
	if (!(vec->data) || vec->size + 1 > vec->alloc)
		if (vec_alloc(vec))
			return (1);
	ft_memcpy(vec->data + (vec->size * vec->el_size), el, vec->el_size);
	++(vec->size);
	return (0);
}

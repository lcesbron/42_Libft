/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:29:06 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/03 18:45:11 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "mem.h" 

void	vec_add(t_vec **vec, void *el)
{
	if (!((*vec)->data) || (*vec)->size + (*vec)->el_size > (*vec)->alloc)
		vec_alloc(vec);
	else
		ft_memcpy((*vec)->data + (*vec)->size, el, (*vec)->el_size);
	++((*vec)->size);
}

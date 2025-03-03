/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:22:25 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/03 18:09:21 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "mem.h"
#include <stddef.h>

t_vec	vec_create(unsigned int el_size)
{
	t_vec	ret;

	ret.data = NULL;
	ret.alloc = 0;
	ret.size = 0;
	ret.el_size = el_size;
	return (ret);
}

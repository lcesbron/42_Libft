/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:40:51 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/03 18:43:21 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include <stdlib.h>

void	vec_free(t_vec *vec)
{
	free(vec->data);
	vec->data = NULL;
}

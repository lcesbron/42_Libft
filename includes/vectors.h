/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:13:33 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/03 18:46:19 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stddef.h>

# define VEC_SIZE 4

typedef struct s_vec	t_vec;

// for the moment vec->size & vec->alloc refers to the 
// size in elements and not the size in bytes
struct s_vec
{
	void	*data;
	size_t	size;
	size_t	alloc;
	size_t	el_size;
};

// char return values are for errors

t_vec	vec_create(unsigned int el_size);
char	vec_add(t_vec **vec, void *el);
char	vec_alloc(t_vec *vec);

#endif
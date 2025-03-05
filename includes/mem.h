/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:52:58 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/05 22:34:25 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	ft_swap(int *a, int *b);
void	ft_uswap(unsigned int *a, unsigned int *b);

#endif
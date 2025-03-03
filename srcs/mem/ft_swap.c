/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:30:05 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/03 18:49:20 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// /!\ will not work if *a & *b are the same adress.
void	ft_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	ft_uswap(unsigned int *a, unsigned int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

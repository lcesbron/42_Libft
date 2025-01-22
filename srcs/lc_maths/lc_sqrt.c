/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:08:40 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/22 17:33:12 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	lc_int_sqrt(int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j * j <= nb || i * i >= nb)
	{
		i++;
		j++;
	}
	return (j);
}

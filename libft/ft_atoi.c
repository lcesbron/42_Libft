/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                              				   	  +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:55:58 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/14 09:33:22 by lcesbron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

int	ft_atoi(const char *nptr)
{
	int						sign;
	unsigned long long int	nb;

	sign = 1;
	nb = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		sign = 44 - *nptr;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
		if (nb > __LONG_MAX__ && sign == 1)
			return (-1);
		else if (nb > __LONG_MAX__ && sign == -1)
			return (0);
	}
	return (nb * sign);
}

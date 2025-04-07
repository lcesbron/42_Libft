/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:35:32 by lcesbron          #+#    #+#             */
/*   Updated: 2025/04/08 01:24:45 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

// TODO: overflow detection

static void	lc_atof_init(const char **nptr, double *mult, double *ret,
			char *sign)
{
	*sign = 1;
	*ret = 0.0;
	*mult = 0.1;
	while (lc_isspace(**nptr))
		++*nptr;
	if (**nptr == '+' || **nptr == '-')
	{
		*sign = 44 - **nptr;
		++*nptr;
	}
}

double	lc_atof(const char *nptr)
{
	double	ret;
	double	mult;
	char	sign;

	lc_atof_init(&nptr, &mult, &ret, &sign);
	while (ft_isdigit(*nptr))
	{
		ret = (10 * ret) + (*nptr - '0');
		++nptr;
	}
	if (*nptr != ',' && *nptr != '.')
		return (ret * sign);
	++nptr;
	while (ft_isdigit(*nptr) && mult > 1e-7)
	{
		ret += (*nptr - '0') * mult;
		mult /= 10;
		++nptr;
	}
	return (ret * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:23:04 by lcesbron          #+#    #+#             */
/*   Updated: 2025/02/21 18:12:42 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"
#include "limits.h"

static void init_strtol(char **str, char **endptr, char *error, int *neg)
{
	*endptr = *str;
	while (lc_isspace(**str))
		++(*str);
	if (**str == '-' || **str == '+')
	{
		*neg = 44 - **str;
		++(*str);
	}
	else
		*neg = 1; 
	*error = 0;
}

long int lc_strtol(char *str, char **endptr, int base)
{
	long int	ret;
	int 		neg;
	char		c;
	char		error;

	ret = 0;
	init_strtol(&str, endptr, &error, &neg);
	while (ft_isalnum(*str))
	{
		if (ft_isdigit(*str))
			c = *str - '0';
		else
			c = ft_tolower(*str) - 'a' + 10;
		if (c >= base || ((long)(ret * base + c) / base != ret 
			&& !(neg == -1 && (long)(ret * base + c) == LONG_MIN)))
			error = 1;
		else
			ret = ret * base + c;
		str++;
	}
	if (!error)
	{
		*endptr = str;
		return (ret * neg);
	}
	return (-1);
}

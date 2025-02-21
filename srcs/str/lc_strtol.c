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

static void init_strtol( char **str, unsigned long int *cutoff, int *cutlim, int *neg, int base)
{
	while (lc_isspace(**str))
		++(*str);
	if (**str == '-' || **str == '+')
	{
		*neg = 44 - **str;
		++(*str);
	}
	else
		*neg = 1; 
	if (*neg > 0)
		*cutoff = LONG_MAX;
	else if (*neg < 0)
		*cutoff =  - LONG_MIN;
	*cutoff /= base;
	*cutlim = *cutoff % base;
}

long lc_strtol(char *str, char **endptr, int base)
{
	long int			ret;
	unsigned long int	cutoff;
	int					cutlim;
	int 				neg;
	char				c;

	ret = 0;
	init_strtol(&str, &cutoff, &cutlim, &neg, base);
	while (ft_isalnum(*str))
	{
		if (ft_isdigit(*str))
			c = *str - '0';
		else
			c = ft_tolower(*str) - 'a' + 10;
		if (c < base && !(ret > cutoff) && !(ret == cutoff && c > cutlim))
			ret = ret * base + c;
		else
			return (-1);
		str++;
	}
	*endptr = str;
	return (ret * neg);
}

#include <stdio.h>

int	main(void)
{
	char *test = "42 54 456 65454 ff 9223372036854775807";
	printf("%ld\n", lc_strtol(test, &test, 10));
	printf("%ld\n", lc_strtol(test, &test, 10));
	printf("%ld\n", lc_strtol(test, &test, 10));
	printf("%ld\n", lc_strtol(test, &test, 10));
	printf("%ld\n", lc_strtol(test, &test, 16));
	printf("%ld\n", lc_strtol(test, &test, 10));
}

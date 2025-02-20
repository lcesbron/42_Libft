/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:23:04 by lcesbron          #+#    #+#             */
/*   Updated: 2025/02/20 16:06:27 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

long lc_strtol(char *str, char **endptr, int base)
{
	long int	ret;
	long int	cutoff;
	int			cutlim;
	int			error;
	char		c;

	while (lc_isspace(*str))
		++str;
	
}
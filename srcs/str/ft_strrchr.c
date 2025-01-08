/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:09:29 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:21:50 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0 && s[i] != c % 256)
	{
		i--;
	}
	if (i >= 0 && s[i] == c % 256)
		return ((char *)(&s[i]));
	return (NULL);
}

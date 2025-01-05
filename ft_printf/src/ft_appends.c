/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appends.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:37:53 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/20 13:33:26 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strappend(char *dest, const char *src)
{
	int	size;

	if (!src)
		return (ft_strappend(dest, "(null)"));
	size = 0;
	while (src[size])
	{
		dest[size] = src[size];
		size++;
	}
	return (size);
}

int	ft_charappend(char *dest, char c)
{
	*dest = c;
	return (1);
}

int	ft_ptrappend(char *dest, void *ptr)
{
	if (ptr == 0)
		return (ft_strappend(dest, "(nil)"));
	dest += ft_strappend(dest, "0x");
	return (ft_ullint16append_min(dest, (unsigned long long int)ptr) + 2);
}

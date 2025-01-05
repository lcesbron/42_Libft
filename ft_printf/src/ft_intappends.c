/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intappends.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:35:18 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/25 10:46:27 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_uint10append(char *dest, unsigned int n)
{
	int	len;
	int	size;

	len = ft_uint10len(n) - 1;
	size = len + 1;
	while (len >= 0)
	{
		dest[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (size);
}

int	ft_int10append(char *dest, int n)
{
	int	len;
	int	neg;
	int	size;

	if (n == INT_MIN)
		return (ft_strappend(dest, "-2147483648"));
	len = ft_int10len(n) - 1;
	size = len + 1;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	else
		neg = 0;
	while (len >= 0)
	{
		dest[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg == 1)
		dest[0] = '-';
	return (size);
}

int	ft_int16append_min(char *dest, unsigned int n)
{
	int	len;
	int	size;

	len = ft_int16len(n) - 1;
	size = len + 1;
	while (len >= 0)
	{
		dest[len] = "0123456789abcdef"[n % 16];
		n /= 16;
		len--;
	}
	return (size);
}

int	ft_ullint16append_min(char *dest, unsigned long long int n)
{
	int	len;
	int	size;

	len = ft_ullint16len(n) - 1;
	size = len + 1;
	while (len >= 0)
	{
		dest[len] = "0123456789abcdef"[n % 16];
		n /= 16;
		len--;
	}
	return (size);
}

int	ft_int16append_maj(char *dest, unsigned int n)
{
	int	len;
	int	size;

	len = ft_int16len(n) - 1;
	size = len + 1;
	while (len >= 0)
	{
		dest[len] = "0123456789ABCDEF"[n % 16];
		n /= 16;
		len--;
	}
	return (size);
}

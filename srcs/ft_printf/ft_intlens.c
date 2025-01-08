/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:48 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/22 16:44:46 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_int10len(int n)
{
	int		len;
	char	neg;

	len = 1;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	else
		neg = 0;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len + neg);
}

int	ft_uint10len(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_int16len(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_ullint16len(unsigned long long int n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_ptrlen(void *ptr)
{
	if (ptr == 0)
		return (5);
	return (ft_ullint16len((unsigned long long int)ptr) + 2);
}

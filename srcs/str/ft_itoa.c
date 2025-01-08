/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:29:41 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/12 19:12:46 by lcesbron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	ft_num_len(int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*ret;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	else
		sign = 0;
	len = ft_num_len(n);
	ret = ft_calloc(len + sign + 1, 1);
	if (!ret)
		return (NULL);
	while (len-- + sign > 0)
	{
		ret[len + sign] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		ret[0] = '-';
	return (ret);
}

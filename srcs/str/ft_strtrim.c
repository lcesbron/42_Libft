/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:43:50 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/12 11:28:20 by lcesbron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	ft_isinset(int c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (c == '\0');
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	char	*ret;

	slen = ft_strlen(s1);
	while (slen >= 0 && ft_isinset(s1[slen], set))
		slen--;
	while (ft_isinset(*s1, set) && *s1 && slen >= 0)
	{
		s1++;
		slen--;
	}
	ret = ft_substr(s1, 0, slen + 1);
	return (ret);
}

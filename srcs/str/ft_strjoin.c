/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:30:21 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:20:28 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ret = malloc(s1len + s2len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, s1len + 1);
	ft_strlcat(ret, s2, s1len + s2len + 1);
	return (ret);
}

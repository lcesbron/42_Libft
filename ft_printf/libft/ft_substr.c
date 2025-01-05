/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:57:16 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/12 14:22:15 by lcesbron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	size;

	size = ft_strlen(s);
	if (start >= size)
		len = 0;
	else if (size - start <= len)
	{
		len = size - start;
		s = s + start;
	}
	else
		s = s + start;
	substring = malloc(len + 1);
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s, len + 1);
	return (substring);
}

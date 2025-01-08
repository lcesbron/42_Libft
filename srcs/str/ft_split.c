/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:30:27 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:22:48 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

static void	*ft_freeall(char **tab, int strings)
{
	while (strings >= 0)
	{
		free(tab[strings]);
		--strings;
	}
	free(tab);
	return (NULL);
}

static int	ft_count_strings(char const *s, char c)
{
	int	strings;
	int	i;

	i = 0;
	strings = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			strings++;
		i++;
	}
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*next_c;
	int		strings;
	char	**ret;

	strings = ft_count_strings(s, c);
	ret = malloc(sizeof(char *) * (strings + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < strings)
	{
		while (*s == c)
			s++;
		next_c = ft_strchr(s, c);
		if (next_c)
			ret[i] = ft_substr(s, 0, next_c - s);
		else
			ret[i] = ft_substr(s, 0, ft_strlen(s));
		if (!ret[i])
			return (ft_freeall(ret, i - 1));
		i++;
		s = next_c;
	}
	return (ret[strings] = NULL, ret);
}

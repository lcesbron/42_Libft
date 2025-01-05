/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:02:46 by lcesbron          #+#    #+#             */
/*   Updated: 2024/12/05 15:02:20 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_line_len(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && (s[i] != '\n'))
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

void	*free_buffer_line(char *buffer, char *line)
{
	if (buffer)
		buffer[0] = 0;
	if (line)
		free(line);
	return (NULL);
}

int	str_line_cpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = 0;
	return (i);
}

void	minimize_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (buffer[i] == '\n')
		++i;
	j = 0;
	while (i + j < READ_SIZE && buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		++j;
	}
	while (j <= READ_SIZE)
	{
		buffer[j] = 0;
		++j;
	}
}

char	*buffer_to_line(char *buffer, char *line, size_t *el_index, bool *error)
{
	char	*ret;

	if (!buffer || !buffer[0])
		return (NULL);
	ret = malloc(str_line_len(line) + str_line_len(buffer) + 1);
	if (!ret)
	{
		*error = true;
		return (free_buffer_line(NULL, line));
	}
	if (line)
		*el_index += str_line_cpy(ret, line);
	*el_index += str_line_cpy(&(ret[*el_index]), buffer) - 1;
	free_buffer_line(NULL, line);
	return (ret);
}

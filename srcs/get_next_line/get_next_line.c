/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:02:49 by lcesbron          #+#    #+#             */
/*   Updated: 2024/12/05 14:25:42 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buffer[READ_SIZE + 1UL] = {0};
	char		*line;
	size_t		el_index;
	ssize_t		mem_read;
	bool		error;

	error = false;
	mem_read = READ_SIZE;
	el_index = 0;
	line = NULL;
	line = buffer_to_line(buffer, line, &el_index, &error);
	while ((!line || line[el_index] != '\n') && mem_read == READ_SIZE && !error)
	{
		el_index = 0;
		mem_read = read(fd, buffer, READ_SIZE);
		if (mem_read < 0 || (!mem_read && !line))
			return (free_buffer_line(buffer, line));
		buffer[mem_read] = 0;
		if (mem_read)
			line = buffer_to_line(buffer, line, &el_index, &error);
	}
	if (error)
		return (free_buffer_line(buffer, line));
	minimize_buffer(buffer);
	return (line);
}

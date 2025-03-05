/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:59:14 by lcesbron          #+#    #+#             */
/*   Updated: 2025/03/05 22:34:50 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define READ_SIZE BUFFER_SIZE

// GET_NEXT_LINE

char	*get_next_line(int fd);

// UTILS

char	*buffer_to_line(char *buffer, char *line, size_t *el_index, bool *err);
int		str_line_cpy(char *dest, char *src);
int		str_line_len(const char *s);
void	*free_buffer_line(char *buffer, char *line);
void	minimize_buffer(char *buffer);

#endif
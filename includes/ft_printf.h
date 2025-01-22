/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:21 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/25 13:19:16 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...)__attribute__((format(printf, 1, 2)));

// LENS 

int		ft_retlen(const char *format, va_list args);
int		ft_int10len(int n);
int		ft_int16len(unsigned int n);
int		ft_uint10len(unsigned int n);
int		ft_ullint16len(unsigned long long int n);
int		ft_ptrlen(void *ptr);

// APPENDS

int		ft_strappend(char *dest, const char *src);
int		ft_int10append(char *dest, int n);
int		ft_int16append_min(char *dest, unsigned int n);
int		ft_int16append_maj(char *dest, unsigned int n);
int		ft_ptrappend(char *dest, void *ptr);
int		ft_charappend(char *dest, char c);
int		ft_uint10append(char *dest, unsigned int n);
int		ft_ullint16append_min(char *dest, unsigned long long int n);
void	ft_fill(char *str, const char *format, va_list args);

#endif

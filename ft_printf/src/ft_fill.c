/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:10:40 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/22 16:43:49 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// returns len - 1 for the same reason as :
// static int	ft_arglen(int format, ...) go check there
static int	ft_fill_arg(char *str, int format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	if (format == 'c')
		len = ft_charappend(str, va_arg(args, int));
	else if (format == 's')
		len = ft_strappend(str, va_arg(args, const char *));
	else if (format == 'p')
		len = ft_ptrappend(str, va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len = ft_int10append(str, va_arg(args, int));
	else if (format == 'u')
		len = ft_uint10append(str, va_arg(args, unsigned int));
	else if (format == 'x')
		len = ft_int16append_min(str, va_arg(args, unsigned int));
	else if (format == 'X')
		len = ft_int16append_maj(str, va_arg(args, unsigned int));
	va_end(args);
	return (len);
}

void	ft_fill(char *str, const char *format, va_list args)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 'd' || *format == 'i')
				str += ft_fill_arg(str, *format, va_arg(args, int));
			else if (*format == '%')
				str += ft_charappend(str, '%');
			else if (*format == 's')
				str += ft_fill_arg (str, *format, va_arg(args, const char *));
			else if (*format == 'p')
				str += ft_fill_arg(str, *format, va_arg(args, void *));
			else if (*format == 'u' || *format == 'x' || *format == 'X')
				str += ft_fill_arg(str, *format, va_arg(args, unsigned int));
			else
			{
				str += ft_charappend(str, '%');
				format--;
			}
		}
		else
			*str++ = *format;
		format++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:03:56 by lcesbron          #+#    #+#             */
/*   Updated: 2024/11/25 10:48:52 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	ft_printf_strlen(const char *s)
{
	int	i;

	if (!s)
		return (6);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_charlen(char c)
{
	(void)c;
	return (1);
}

// returns the len minus one because of the use of this function in ft_retlen
// indeed, whatever happens, retlen will always increase len by one.
// So we need to returns the length of an arg minus one, 
// because this one will be added again.
static int	ft_arglen(int format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	if (format == 'c')
		len = (ft_charlen(va_arg(args, int)));
	else if (format == 's')
		len = (ft_printf_strlen(va_arg(args, const char *)));
	else if (format == 'p')
		len = (ft_ptrlen(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		len = (ft_int10len(va_arg(args, int)));
	else if (format == 'u')
		len = (ft_uint10len(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		len = (ft_int16len(va_arg(args, unsigned int)));
	va_end(args);
	return (len - 1);
}

int	ft_retlen(const char *format, va_list args)
{
	int	len;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 'd' || *format == 'i')
				len += ft_arglen(*format, va_arg(args, int));
			else if (*format == '%')
				len += 0;
			else if (*format == 's')
				len += ft_arglen(*format, va_arg(args, const char *));
			else if (*format == 'p')
				len += ft_arglen(*format, va_arg(args, void *));
			else if (*format == 'u' || *format == 'x' || *format == 'X')
				len += ft_arglen(*format, va_arg(args, unsigned int));
			else
				format--;
		}
		len++;
		format++;
	}
	return (len);
}

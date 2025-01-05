/* ************************************************************************** */
/*									   									      */
/*														  :::	   ::::::::   */
/*   ft_printf.c           	                            :+:      :+:    :+:   */
/*												      +:+ +:+	      +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>	    +#+  +:+	   +#+	      */
/*												  +#+#+#+#+#+	+#+		      */
/*   Created: 2024/11/14 15:24:42 by lcesbron	       #+#    #+#	    	  */
/*   Updated: 2024/11/18 19:46:19 by lcesbron         ###   ########.fr       */
/*																		      */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	args_cpy;
	int		len;
	char	*str;

	if (!format)
		return (-1);
	va_start(args, format);
	va_copy(args_cpy, args);
	len = ft_retlen(format, args_cpy);
	va_end(args_cpy);
	str = malloc(len + 1);
	if (!str)
	{
		va_end(args);
		return (0);
	}
	va_copy(args_cpy, args);
	ft_fill(str, format, args_cpy);
	va_end(args_cpy);
	va_end(args);
	str[len] = 0;
	len = write(1, str, len);
	free(str);
	return (len);
}

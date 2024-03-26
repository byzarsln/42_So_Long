/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:46:50 by beyarsla          #+#    #+#             */
/*   Updated: 2023/12/27 15:25:15 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_count(char c, va_list arg)
{
	int	a;

	a = 0;
	if (c == 'c')
		a += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		a += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		a += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		a += ft_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		a += ft_hex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		a += ft_hex(va_arg(arg, unsigned int), 1);
	else if (c == 'p')
	{
		a += ft_putstr("0x");
		a += ft_pointer(va_arg(arg, unsigned long), 0);
	}
	else
		a += ft_putchar('%');
	return (a);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i] != '\0')
				i++;
			count += ft_count(str[i], arg);
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(arg);
	return (count);
}

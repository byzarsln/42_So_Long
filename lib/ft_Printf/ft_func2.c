/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:23:07 by beyarsla          #+#    #+#             */
/*   Updated: 2023/12/27 15:23:44 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int u)
{
	int	i;

	i = 0;
	if (u >= 0 && u <= 9)
		i += ft_putchar(u + '0');
	else
	{
		i += ft_unsigned(u / 10);
		i += ft_unsigned(u % 10);
	}
	return (i);
}

int	ft_hex(unsigned int a, int b)
{
	return (ft_pointer(a, b));
}

int	ft_pointer(unsigned long h, int b)
{
	int	i;

	i = 0;
	if (h >= 16)
		i += ft_pointer(h / 16, b);
	if ((h % 16) < 10)
		i += ft_putchar((h % 16) + '0');
	else
	{
		if (b == 0)
			i += ft_putchar((h % 16) + 87);
		else
			i += ft_putchar((h % 16) + 55);
	}
	return (i);
}

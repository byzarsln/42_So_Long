/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrsezer <ibrsezer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:50:22 by ibrsezer          #+#    #+#             */
/*   Updated: 2024/01/02 13:28:44 by ibrsezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static char	*value(char *str, unsigned int number, long int len)
{
	while (number > 0)
	{
		str[len--] = (number % 10) + 48;
		number = number / 10;
	}
	return (str);
}

static int	counter(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	long int		length;
	unsigned int	number;

	length = counter(n);
	s = malloc(length * sizeof(char) + 1);
	if (!s)
		return (NULL);
	s[length--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = value(s, number, length);
	return (s);
}

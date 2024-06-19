/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:41:47 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/06/19 12:48:31 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	buffer[10];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		len++;
	}
	return (len);
}

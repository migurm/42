/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:59:51 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/08/26 12:04:32 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_hexa_digits(int uppercase)
{
	if (uppercase)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

int	ft_puthex(unsigned long num, int uppercase)
{
	char	*hexa_digits;
	char	buffer[16];
	int		i;
	int		len;

	i = 0;
	len = 0;
	hexa_digits = ft_get_hexa_digits(uppercase);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		buffer[i++] = hexa_digits[num % 16];
		num /= 16;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		len++;
	}
	return (len);
}

int	ft_putpointer(void	*ptr)
{
	int	len;

	len = 0;
	if (ptr == NULL)
	{
		len += write(1, "(nil)", 5);
	}
	else
	{
		len += write(1, "0x", 2);
		len += ft_puthex((unsigned long)ptr, 0);
	}
	return (len);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);
	return (len);
}

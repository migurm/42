/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:59:51 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/01/14 20:35:00 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Char

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

//String

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int ft_puthex(unsigned long num, int uppercase)
{
	char *hexa_digits;
	char buffer[16];
	int i, len;

	i = len = 0;
	hexa_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (num == 0)
	{
		write(1, "0", 1);
		return 1;
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
	
	return len;
}

int	ft_putpointer(void	*ptr)
{
	int len;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_puthex((unsigned long)ptr, 0);

	return len;
}

int ft_putnbr(int n)
{
	char *str;
	int len;

	str = ft_itoa(n);
	if(!str)
		return (0);
	len = ft_putstr(str);
	free(str);

	return len;
}

int ft_putnbr_unsigned(unsigned int n) {
    char buffer[10];
    int i = 0;
    int len = 0;

    if (n == 0) 
	{
        write(1, "0", 1);
        return 1;
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

    return len;
}
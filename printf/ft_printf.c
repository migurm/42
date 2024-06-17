/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:40:33 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/01/14 19:55:39 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
        return ft_putpointer(va_arg(ap, void *));
	else if ((c == 'd') || (c == 'i'))
        return ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
        return ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
        return ft_puthex(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
        return ft_puthex(va_arg(ap, unsigned int), 1);
	else if (c == '%')
        return ft_putchar('%');
}



int	ft_printf(char *str, ...)
{
	int		i;
	int		l;
	va_list	ap;

	va_start(ap, str);
	l = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			l += ft_format(str[++i], ap);
		else
			l += write(1, &str[i], 1);
	}
	va_end(ap);
	return (l);
}

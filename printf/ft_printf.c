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
		return (ft_putchar_fd(va_arg(ap, char), 1), 1);
	if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1), 1);
	else if (c == 'p')
		(void)0;
	else if (c == 'd')
		(void)0;
	else if (c == 'i')
		(void)0;
	else if (c == 'u')
		(void)0;
	else if (c == 'x')
		(void)0;
	else if (c == 'X')
		(void)0;
	else if (c == '%')
		(void)0;
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

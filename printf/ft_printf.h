/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:41:34 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/06/19 12:48:40 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_puthex(unsigned long num, int uppercase);
int		ft_putpointer(void	*ptr);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);

#endif
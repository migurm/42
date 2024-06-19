/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:36:08 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/06/19 12:48:56 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	if (n < 0)
		length++;
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = ft_numlen(n);
	res = malloc((length + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[length] = '\0';
	while (n > 0)
	{
		res[--length] = '0' + (n % 10);
		n /= 10;
	}
	return (res);
}

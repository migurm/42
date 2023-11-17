/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:36:08 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/17 21:17:24 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	length;

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
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	length = ft_numlen(n);
	res = malloc((length + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	i = length - 1;
	while (n > 0)
	{
		res[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	res[length] = '\0';
	return (res);
}

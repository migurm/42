/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:10:00 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 14:14:15 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
	}
	if ((char)c == 0)
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

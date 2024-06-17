/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:34:20 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 14:20:56 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*res;

	i = -1;
	res = NULL;
	while (str[++i])
	{
		if (str[i] == (char)c)
		{
			res = ((char *)&str[i]);
		}
	}
	if ((char)c == 0)
	{
		return ((char *)&str[i]);
	}
	return (res);
}

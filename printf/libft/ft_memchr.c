/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:19:15 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 17:29:45 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*res;
	char		*cpy;

	cpy = (char *)s;
	i = -1;
	res = NULL;
	while (++i < n)
	{
		if (cpy[i] == (char)c)
		{
			return ((void *)&cpy[i]);
		}
	}
	if (n == 0)
	{
		return (NULL);
	}
	return (res);
}

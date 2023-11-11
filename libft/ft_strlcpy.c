/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:20:46 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 13:56:07 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t size)
{
	size_t	i;
	size_t	o_size;

	o_size = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (o_size);
	while (src[i] != '\0' && i < size -1)
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (o_size);
}

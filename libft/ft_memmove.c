/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:04:07 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 18:59:16 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copy_dst;
	unsigned char	*copy_src;
	size_t			i;

	copy_dst = (unsigned char *)dst;
	copy_src = (unsigned char *)src;
	if (copy_dst > copy_src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			copy_dst[i] = copy_src[i];
		}
	}
	else if (copy_dst < copy_src)
	{
		i = 0;
		while (i < len)
		{
			copy_dst[i] = copy_src[i];
			i++;
		}
	}
	return (dst);
}

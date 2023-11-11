/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:31:10 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 17:51:31 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*copy_dst;
	unsigned char	*copy_src;
	size_t			i;

	i = -1;
	copy_dst = (unsigned char *) dst;
	copy_src = (unsigned char *) src;
	if (copy_dst == NULL && copy_src == NULL)
		return (NULL);
	while (++i < n)
		copy_dst[i] = copy_src[i];
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:38:32 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 13:11:51 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	val;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) mem;
	val = (unsigned char) c;
	while (i < len)
		ptr[i++] = val;
	return (mem);
}

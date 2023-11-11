/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:34:55 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 19:49:03 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		size;
	char	*pointer;

	size = ft_strlen(str);
	pointer = (char *)malloc((size + 1) * sizeof(char));
	if (pointer == NULL)
		return (NULL);
	ft_memcpy(pointer, str, (size + 1) * sizeof(char));
	return (pointer);
}

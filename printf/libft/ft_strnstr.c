/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:08:06 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 15:02:34 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	match;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i + ft_strlen(needle) <= len)
	{
		if (haystack[i] == needle[0])
		{
			k = -1;
			match = 1;
			while (match && needle[++k])
				if (haystack[i + k] != needle[k])
					match = 0;
			if (match)
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}

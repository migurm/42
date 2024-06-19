/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:36:13 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/17 20:52:43 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_str(const char *str, char c)
{
	while (*str && c != *str)
		str++;
	return (c == *str);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_in_str(set, s1[start]))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_in_str(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

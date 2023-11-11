/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:54:36 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 20:39:18 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t num1, size_t num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str_res;
	unsigned int	len_string;
	unsigned int	i;

	len_string = ft_strlen(s);
	if (start >= len_string)
		return (ft_strdup(""));
	str_res = malloc((ft_min(len_string - start, len) + 1) * sizeof(char));
	if (str_res == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str_res[i] = s[start + i];
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}

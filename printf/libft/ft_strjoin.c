/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:55:59 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 23:34:12 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str_res;
	size_t	i;
	size_t	k;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str_res = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (str_res == NULL)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		str_res[i] = s1[i];
	k = -1;
	while (++k < len_s2)
	{
		str_res[i] = s2[k];
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}

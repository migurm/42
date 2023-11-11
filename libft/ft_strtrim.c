/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:36:13 by mrueda-m          #+#    #+#             */
/*   Updated: 2023/11/11 23:50:50 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str_res;
	size_t	i;
	size_t	k;
	size_t	len_s1;

	i = 0;
	k = 0;
	while (set[i])
	{
		if (set[i] != s1[i])
			break ;
		else
			i++;
	}

}


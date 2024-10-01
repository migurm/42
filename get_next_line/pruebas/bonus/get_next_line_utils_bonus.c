/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelr <miguelr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:50:23 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/09/25 11:15:31 by miguelr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	str_size;

	str_size = -1;
	while (str[++str_size])
	{
	}
	return (str_size);
}

char	*ft_strchar(const char *str, int c)
{
	int	index;

	if (!str)
		return (NULL);
	index = -1;
	while (str[++index])
	{
		if (str[index] == (char) c)
			return ((char *)&str[index]);
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		size;
	char	*new_str;
	int		index;

	index = -1;
	size = ft_strlen(str);
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (str[++index])
		new_str[index] = str[index];
	new_str[index] = '\0';
	return ((char *) &new_str[0]);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	new_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	while (str1[++i])
		new_str[i] = str1[i];
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	return (new_str);
}

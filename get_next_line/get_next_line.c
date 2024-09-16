/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelr <miguelr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:22:17 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/09/16 12:23:25 by miguelr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_buffer(char *buffer, int fd)
{
	char	*filled_buffer;
	int		readed_lines;
	char	*temp;

	filled_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!filled_buffer)
		return (NULL);
	while (!ft_strchar(buffer, '\n'))
	{
		readed_lines = read(fd, filled_buffer, BUFFER_SIZE);
		if (readed_lines <= 0)
			return (free(filled_buffer), buffer);
		filled_buffer[readed_lines] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, filled_buffer);
		free(temp);
		if (!buffer)
			return (free(filled_buffer), NULL);
	}
	free(filled_buffer);
	return (buffer);
}

char	*get_clear_line(char *buffer)
{
	char	*line;
	int		index;

	index = -1;
	while (buffer[++index] && buffer[index] != '\n')
	{
	}
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*clean_buffer(char *old_buffer)
{
	char	*new_buffer;
	int		start;

	start = 0;
	while (old_buffer[start] && old_buffer[start] != '\n')
		start++;
	if (old_buffer[start] == '\0')
		return (free(old_buffer), NULL);
	new_buffer = ft_strdup(&old_buffer[start + 1]);
	free(old_buffer);
	if (*new_buffer == '\0')
	{
		free(new_buffer);
		return (NULL);
	}
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	buffer = fill_buffer(buffer, fd);
	if (buffer == NULL)
		return (NULL);
	line = get_clear_line(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}

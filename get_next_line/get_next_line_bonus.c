/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelr <miguelr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:22:17 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/09/16 13:39:50 by miguelr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char *clean_buffer(char *old_buffer)
{
    char *new_buffer;
    int i = 0;

    while (old_buffer[i] && old_buffer[i] != '\n')
        i++;
    if (!old_buffer[i])
    {
        free(old_buffer);
        return (NULL);
    }

    new_buffer = ft_strdup(&old_buffer[i + 1]);
    free(old_buffer);
    return (*new_buffer ? new_buffer : NULL);
}


char	*get_next_line(int fd)
{
    static char *buffers[FD_MAX];
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
        return (NULL);

    buffers[fd] = fill_buffer(buffers[fd], fd);
    if (!buffers[fd])
        return (NULL);

    line = get_clear_line(buffers[fd]);
    buffers[fd] = clean_buffer(buffers[fd]);

    return (line);
}

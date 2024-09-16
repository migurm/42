/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelr <miguelr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:22:17 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/09/16 11:07:34 by miguelr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Devolver los segmentos del archivo necesarios hasta encontrar el salto de linea o el final.
Recibe: lo leido hasta ahora que estaba guardando estaticamente, y el file descriptor del archivo a leer
Devuelve: la cadena de caracteres que puede contener \n
*/
char    *fill_buffer(char *buffer, int fd)
{
    char    *filled_buffer;
    int     readed_lines;
    char    *temp;

	filled_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!filled_buffer)
		return (NULL);

    while (!ft_strchar(buffer, '\n'))
    {
		readed_lines = read(fd, filled_buffer, BUFFER_SIZE);
		if (readed_lines < 0)
		{
			free(filled_buffer);
			return (NULL);
		}
		else if (readed_lines == 0)
			break;

        filled_buffer[readed_lines] = '\0';
        temp = buffer;
		buffer = ft_strjoin(buffer, filled_buffer);
		//Unimos ambos buffers y liberamos el primero
        free(temp);
        if (!buffer) //Si no podemos unir
        {
            free(filled_buffer);
            return (NULL);
        }
    }
    free(filled_buffer);
	return (buffer); // Cuando hayamos encontrado el fin o
	// el salto de línea, devolvemos la cadena resultante.
}

/*
Copiar del buffer caracteres hasta encontrar el salto de línea (incluído)
Recibe: el buffer
Devuelve: La linea (con el salto de linea)
Si no encuentra el salto de linea en el buffer lo devuelve al completo
*/
char    *get_clear_line(char *buffer)
//PENDIENTE DE TERMINAR
	//Vamos a recibir aquí una cadena de caracteres que seguramente tenga
	//en una posición intermedia el salto de línea... o sea el final del texto.
	//Tenemos que devolver la cadena de caracteres que hay antes del salto de linea o fin
{
    char	*line;
    int		index;

    index = -1;
    
    // Contamos cuántos caracteres hay hasta el salto de línea o fin del buffer
    while (buffer[++index] && buffer[index] != '\n')
	{
	}		
    // Reservamos memoria para la línea, incluyendo espacio para el '\n' y el '\0'
    line = (char *)malloc(sizeof(char) * (index + 2)); // +2 por el '\n' y '\0'
    if (!line)
		return (NULL);

    // Copiamos los caracteres del buffer a line
    index = 0;
    while (buffer[index] && buffer[index] != '\n')
    {
        line[index] = buffer[index];
        index++;
    }

    // Si encontramos un '\n', también lo copiamos a line
    if (buffer[index] == '\n')
    {
        line[index] = '\n';
        index++;
    }

    // Añadimos el terminador nulo '\0'
    line[index] = '\0';

    return (line);
}





/*
Quitar del buffer los caracteres que se encuentran antes del salto de linea (incluído)
Recibe: el antiguo buffer
Devuelve: el nuevo buffer (el antiguo ha sido liberado con free)
Si no hay salto de linea, se devuelve NULL.
*/
char    *clean_buffer(char *old_buffer)
{ 	//PENDIENTE DE TERMINAR
	//Liberar antiguo y reservar memoria para el nuevo.
    //Va a recibir un string que contendrá alomejor el salto de línea, tenemos q almacenar
    //en el buffer saliente el string resultante iniciado desde este salto de línea...

    char    *new_buffer;
    int     start;

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

char    *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(buffer), NULL);
    buffer = fill_buffer(buffer, fd);
    if (buffer == NULL)
        return (NULL);
    line = get_clear_line(buffer);
    buffer = clean_buffer(buffer);
    return (line);
}



#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
/*
int main(void) {
    char *file = "texto.txt";

    int fd = open(file, O_RDONLY);

    char *line;

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    close(fd);

    return (42);
}*/
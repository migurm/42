/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:22:17 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/09/11 09:44:56 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Devolver los segmentos del archivo necesarios hasta encontrar el salto de linea o el final.
Recibe: lo leido hasta ahora que estaba guardando estaticamente, y el file descriptor del archivo a leer
Devuelve: la cadena de caracteres que puede contener \n
*/
char    *rellenar_buffer_hasta_tener_NL_o_EOF(char *buffer, int fd)
{ //PENDIENTE DE TERMINAR
    char    *filled_buffer;
    int     readed_lines;

    //Recibimos un buffer que puede estar vacío... o no
    //A este buffer, le vamos a ir añadiendo lecturas 
    //Hasta encontrar o el fin del archivo, o el salto de línea
	//Inicializamos la variable filled_buffer
	filled_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!filled_buffer)
		return (NULL);

    while (!ft_strchar(buffer, '\n'))
    {//Si viene nulo, es que no hay terminador y salto de línea
	//En ese caso leemos y tiramos en el buffer auxiliar lo leído
		readed_lines = read(fd, filled_buffer, BUFFER_SIZE);
		//Si readed_lines viene menor que el BUFFER_SIZE...se acabó
		//Tenemos que prever los casos de readed_lines -1 y 0 en este punto.
		if (readed_lines < 0)
		{
			free(filled_buffer);
			return (NULL);
		}
		else if (readed_lines == 0)
			break; //Arriba soldado, nos largamos

		buffer = ft_strjoin(buffer, filled_buffer);
		//Unimos ambos buffers 
    }
	return (buffer); // Cuando hayamos encontrado el fin o
	// el salto de línea, devolvemos la cadena resultante.
}

/*
Copiar del buffer caracteres hasta encontrar el salto de línea (incluído)
Recibe: el buffer
Devuelve: La linea (con el salto de linea)
Si no encuentra el salto de linea en el buffer lo devuelve al completo
*/
char    *extraer_linea(char *buffer)
{//PENDIENTE DE TERMINAR
	//Vamos a recibir aquí una cadena de caracteres que seguramente tenga
	//en una posición intermedia el salto de línea... o sea el final del texto.
	//Tenemos que devolver la cadena de caracteres que hay antes del salto de linea o fin
	char	*line;
	int		index;

    line = (char *)malloc(sizeof(char) * (index + 2));
    if (!line)
        return (NULL);
	index = -1;
	while (buffer[++index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
	}
    line[index++] = '\n';
    line[index] = '\0';
    return (line);

}

/*
Quitar del buffer los caracteres que se encuentran antes del salto de linea (incluído)
Recibe: el antiguo buffer
Devuelve: el nuevo buffer (el antiguo ha sido liberado con free)
Si no hay salto de linea, se devuelve NULL.
*/
char    *limpiar_estatica(char *old_buffer)
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
    return (new_buffer);
}

char    *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(buffer), NULL);
    buffer = rellenar_buffer_hasta_tener_NL_o_EOF(buffer, fd);
    if (buffer == NULL)
        return (NULL);
    line = extraer_linea(buffer);
    buffer = limpiar_estatica(buffer);
    return (line);
}

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
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
}
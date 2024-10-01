#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int *fds; //array de file descriptors
    char *line;
    int i;
    int all_files_done = 0;

    if (argc < 2)
    {
        printf("Uso: %s <archivo1> <archivo2> ... <archivoN>\n", argv[0]);
        return 1;
    }

    // Asignamo la cantidad de memoria dependiendo del numero de archivos
    fds = (int *)malloc(sizeof(int) * (argc - 1));
    if (!fds)
        return 1;

    // Abre todos los archivos pasados como argumentos
    for (i = 1; i < argc; i++)
    {
        fds[i - 1] = open(argv[i], O_RDONLY);
        if (fds[i - 1] < 0)
        {
            printf("Error al abrir el archivo: %s\n", argv[i]);
            fds[i - 1] = -1; // Señalamos el archivo que no se encontró
        }
    }

    // Lee intercalando entre los archivos hasta que todos hayan llegado al final
    while (!all_files_done)
    {
        all_files_done = 1; // Buscamos el fallo, si quedan líneas el booleano vuelve a cero
        for (i = 1; i < argc; i++)
        {
            if (fds[i - 1] >= 0) // Si el archivo es válido
            {
                line = get_next_line(fds[i - 1]);
                if (line)
                {
                    printf("%s: %s\n", argv[i], line); // Asegura un salto de línea al imprimir
                    free(line);
                    all_files_done = 0; // Mínimo un archivo no ha llegado al final
                }
            }
        }
    }

    // Cerramos todos
    for (i = 1; i < argc; i++)
    {
        if (fds[i - 1] >= 0)
            close(fds[i - 1]);
    }

    // Liberamos la memoria del array de fds
    free(fds);

    return 0;
}

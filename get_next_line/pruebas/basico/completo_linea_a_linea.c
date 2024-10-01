#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2) // Verifica que se haya pasado un solo argumento
    {
        printf("Uso: %s <nombre_del_archivo>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY); // Abre el archivo especificado por el usuario
    if (fd < 0)
    {
        printf("Error al abrir el archivo: %s\n", argv[1]);
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) // Llama a get_next_line hasta que retorne NULL
    {
        printf("%s", line); // Imprime la línea leída
        free(line); // Libera la memoria asignada para la línea
    }

    close(fd); // Cierra el archivo
    return 0;
}
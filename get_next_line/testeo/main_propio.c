#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void main()
{
	int 	fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("texto.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++, line);
}
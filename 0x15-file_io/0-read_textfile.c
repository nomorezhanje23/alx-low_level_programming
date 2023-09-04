#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads text file & prints to the standard output
 * @filename: name file to be read
 * @letters: number of letters to read and be printed
 * Return: the actual number of letters read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
char *baffz;
ssize_t free;
ssize_t a;
ssize_t b;

free = open(filename, O_RDONLY);
if (free == -1)
return (0);
baffz = malloc(sizeof(char) * letters);
b = read(free, baffz, letters);
a = write(STDOUT_FILENO, baffz, b);

free(baffz);
close(free);
return (a);
}

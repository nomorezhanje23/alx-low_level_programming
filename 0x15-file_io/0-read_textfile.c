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
char *buffer;
ssize_t fl;
ssize_t a;
ssize_t b;

fl = open(filename, O_RDONLY);
if (fl == -1)
return (0);
buffer = malloc(sizeof(char) * letters);
b = read(fl, buffer, letters);
a = write(STDOUT_FILENO, buffer, b);

free(buffer);
close(fl);
return (a);
}

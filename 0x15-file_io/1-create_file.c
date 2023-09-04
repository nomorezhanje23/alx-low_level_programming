#include "main.h"

/**
 * create_file - this creates a file
 * @filename: pointer to file name to be created
 * @text_content:  pointer to thestring which will write to the file
 * Return: 1, and if the function fails return -1
 */

int create_file(const char *filename, char *text_content)
{
int fl, a, one = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (one = 0; text_content[one];)
one++;
}

fl = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
a = write(fl, text_content, one);

if (fl == -1 || a == -1)
return (-1);

close(fl);

return (1);
}

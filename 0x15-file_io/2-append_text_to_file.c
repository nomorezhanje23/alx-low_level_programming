#include "main.h"

/**
 * append_text_to_file - this appends text exactly at the end of a file
 * @filename: name of the file to append to
 * @text_content: NULL-terminated string added at the end of file
 * Return: 1 if successful,or -1 upon failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
if (filename == NULL)
{
return (-1);
}

int file_desc = open(filename, O_WRONLY | O_APPEND);

if (file_desc == -1)
{
return (-1);
}

if (text_content != NULL)
{
ssize_t bytes_written = write(file_desc, text_content, strlen(text_content));

if (bytes_written == -1 || (size_t)bytes_written != strlen(text_content))
{
close(file_desc);
return (-1);
}
}
close(file_desc);
return (1);
}

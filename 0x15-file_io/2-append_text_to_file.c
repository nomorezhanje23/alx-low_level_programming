#include "main.h"

/**
 * append_text_to_file - this appends text exactly at the end of a file
 * @filename: name of the file to append to
 * @text_content: NULL-terminated string added at the end of file
 * Return: 1 if successful,or -1 upon failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int a, b, strch = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (strch = 0; text_content[strch];)
			strch++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	b = write(a, text_content, strch);

	if (a == -1 || b == -1)
		return (-1);

	close(a);

	return (1);
}

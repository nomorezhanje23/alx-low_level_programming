#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - this allocates 1024 bytes to the  buffer
 * @file: the file name that the buffer is storing chars for
 * Return: a pointer to new buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - this close the file descriptor(s)
 * @fd: the file descriptor that will be closed
 */
void close_file(int fd)
{
	int x;

	x = close(fd);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - this copies the contents of a file
 * @argc: the number of arguments supplied to C prog
 * @argv: an array of pointers to  arguments
 * Return: 0 upon success
 */
int main(int argc, char *argv[])
{
	int pre, nex, red, wy;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	pre = open(argv[1], O_RDONLY);
	red = read(pre, buffer, 1024);
	nex = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (pre == -1 || red == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wy = write(nex, buffer, red);
		if (nex == -1 || wy == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		red = read(from, buffer, 1024);
		nex = open(argv[2], O_WRONLY | O_APPEND);

	} while (red > 0);

	free(buffer);
	close_file(pre);
	close_file(nex);

	return (0);
}

#include "main.h"

/**
 * _strncpy - a function that copies a string.
 * @dest: destination string pointer.
 * @src: source string pointer.
 * @n: number of bytes to be used.
 * Return: pointer to destination string.
 */

char *_strncpy(char *dest, char *src, int n)
{
int c_o_b;
/*c_o_b is count_of_bytes*/
for (c_o_b = 0; c_o_b < n && src[c_o_b] != '\0'; c_o_b++)
dest[c_o_b] = src[c_o_b];

for (; c_o_b < n; c_o_b++)
dest[c_o_b] = '\0';

return (dest);
}

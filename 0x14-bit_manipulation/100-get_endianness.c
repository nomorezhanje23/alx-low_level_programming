#include "main.h"

/**
 * get_endianness - checking the endianness
 * Return: 0 for large, or 1 for small
 */
int get_endianness(void)
{
unsigned int x = 1;
char *c = (char *) &x;

return (*c);
}

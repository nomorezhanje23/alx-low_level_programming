#include "main.h"

/**
 * clear_bit - returns the e value of a bit to 0 at any index
 * @n: pointer to the num containing the bit
 * @index: index of the bit to be cleared
 * Return: on sucess return 1, or -1 if unssucessful
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}
*n &= ~(1UL << index);
return (1);
}

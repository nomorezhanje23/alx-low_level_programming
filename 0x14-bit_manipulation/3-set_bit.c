#include "main.h"

/**
 * set_bit - this sets the bit value to 1 at a given index
 * @n: pointer to the num with the bit
 * @index: index of the bit to set
 * Return: 1 upon sucess, or -1 for an error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}
*n |= (1UL << index);
return (1);
}

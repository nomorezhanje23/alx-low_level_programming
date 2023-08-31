#include "main.h"

/**
 * get_bit - returns bit value at an index in a decimal num
 * @n: num to be searched
 * @index: the index of the bit
 * Return: the bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
int bv;

if (index > 63)
return (-1);

bv = (n >> index) & 1;

return (bv);
}

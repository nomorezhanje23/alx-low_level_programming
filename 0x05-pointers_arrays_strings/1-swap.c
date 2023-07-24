#include "main.h"

/**
 * swap_int - take in two variablw integers and swaps them
 * @a: swaps and stores address of b
 * @b: swaps and stores address of a
 * Returns: 0
 */

void swap_int(int *a, int *b)
{
int change;
change = *b;
*b = *a;
*a = change;
}

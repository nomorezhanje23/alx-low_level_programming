#include "main.h"

/**
 * reverse_array - function that reverses the content of an array of integers.
 * @a: pointer to array.
 * @n: number of elements of an array.
 * Return: void.
 */

void reverse_array(int *a, int n)
{
int t, c;
/* t = temporary & c = counter*/
n = n - 1;
c = 0;
while (c <= n)
{
t = a[c];
a[c++] = a[n];
a[n--] = t;
}
}

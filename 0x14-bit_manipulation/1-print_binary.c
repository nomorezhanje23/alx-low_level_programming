#include "main.h"

/**
 * print_binary - this prints the binary equal to decimal num
 * @n: num to print in binary
 */
void print_binary(unsigned long int n)
{
int z, cnt = 0;
unsigned long int mnt;

for (z = 63; z >= 0; z--)
{
mnt = n >> z;

if (mnt & 1)
{
_putchar('1');
cnt++;
}
else if (cnt)
_putchar('0');
}
if (!cnt)
_putchar('0');
}

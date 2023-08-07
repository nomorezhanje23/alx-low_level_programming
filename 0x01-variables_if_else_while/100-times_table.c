#include <stdio.h>

/**
 * print_times_table - Prints the times table of the input starting with 0
 * @n: The value of the times table is to be printed
 */

void print_times_table(int n)
{
if (n < 0 || n > 15)
{
return;
}
for (int i = 0; i <= n; i++)
{
for (int j = 0; j <= n; j++)
{
int product = i * j;
if (product < 10)
_putchar(' ');
}
else if (product < 100)
{
_putchar(' ');
}
if (product >= 100)
{
_putchar(product / 100 + '0')
}
if (product >= 10)
{
_putchar((product / 10) % 10 + '0');
}
_putchar(product % 10 + '0');
if (j < n)
{
_putchar(',');
_putchar(' ');
}
_putchar('\n');
}
}

#include <stdio.h>

/**
 * main - function to combination of two numbers
 *
 * Return: 0 always when the program is successful
 */
int main(void)
{
int i = '0';
int k = '1';
while (i <= '9')
{
while (k <= '9')
{
if (i < k && i != k)
{
putchar(i);
putchar(k);
if (i == '8' && k == '9')
{
putchar('\n');
}
else
{
putchar(',');
putchar(' ');
}
}
k++;
}
k = '0';
i++;
}
return (0);
}

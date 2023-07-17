#include <stdio.h>
/**
 * main - A program that prints all possible combinations of single-digits
 * Return: Always 0 when the program is sucessful
 */
int main(void)
{
int i = '0';
while (i <= '9')
{
putchar(i);
if (i != '9')
{
putchar(',');
putchar(' ');
}
++i;
}
putchar('\n');
return (0);
}

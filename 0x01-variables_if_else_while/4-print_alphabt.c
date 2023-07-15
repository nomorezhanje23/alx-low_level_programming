#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 for a successful program
 */
int main(void)
{
int lowerCase = 'a';
while (lowerCase <= 'z')
{
if (lowerCase != 'e' && lowerCase != 'q')
{
putchar(lowerCase);
}
lowerCase++;
}
putchar('\n');
return (0);
}

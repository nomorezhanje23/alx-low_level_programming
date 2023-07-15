#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0 when its successful
 */

int main(void)
{
int lowerCase = 'a';
int upperCase = 'A';
while (lowerCase <= 'z')
{
putchar(lowerCase);
lowerCase++;
}
while (upperCase <= 'Z')
{
putchar(upperCase);
upperCase++;
}
putchar('\n');
return (0);
}

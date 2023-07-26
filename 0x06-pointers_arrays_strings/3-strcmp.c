#include "main.h"

/**
 * _strcmp - compares two strings.
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 * Return: value < 0 is string is < the other
 * value > 0 if string is greater than the other & 0 if strin is =.
 */

int _strcmp(char *s1, char *s2)
{
int c, cv;
/* c = counter & cv = compare _value*/
c = 0;
while (s1[c] == s2[c] && s1[c] != '\0')
{
c++;
}
cv = s1[c] - s2[c];
return (cv);
}

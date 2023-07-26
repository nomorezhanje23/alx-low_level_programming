#include "main.h"

/**
 * string_toupper - function that changes all lowercase to uppercase letters
 * @x: pointer to string
 * Return: pointer to uppercase string.
 */

char *string_toupper(char *x)
{
int lof;
/* lof = length_of_string */
lof = 0;
while (x[lof] != '\0')
{
if (x[lof] >= 97 && x[lof] <= 122)
{
x[lof] = x[lof] - 32;
}
lof++;
}
return (x);
}

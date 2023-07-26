#include "main.h"

/**
 * cap_string - function that capitalizes all words of a string
 * @s: pointer to string
 * Return: pointer to s.
 */

char *cap_string(char *s)
{
int sc;

/* scan through string ; sc = string_count */

sc = 0;
while (s[sc] != '\0')
{/*if next character after count is a char, capitalise it */
if (s[0] >= 97 && s[0] <= 122)
{
s[0] = s[0] - 32;
}
if (s[sc] == ' ' || s[sc] == '\t' || s[sc] == '\n'
|| s[sc] == ',' || s[sc] == ';' || s[sc] == '.' || s[sc] == '!'
|| s[sc] == '?' || s[sc] == '"' || s[sc] == '(' || s[sc] == ')'
|| s[sc] == '{' || s[sc] == '}')
{
if (s[sc + 1] >= 97 && s[sc + 1] <= 122)
{
s[sc + 1] = s[sc + 1] - 32;
}
}
sc++;
}
return (s);
}

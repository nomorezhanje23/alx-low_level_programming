#include "main.h"

/**
 * flip_bits - the num of bits needed to be  flipped
 * @n: 1st num
 * @m: 2nd num
 * Return: number of bits to be flipped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int ans = n ^ m;
unsigned int cnt = 0;

while (ans > 0)
{
cnt += ans & 1;
ans >>= 1;
}

return (cnt);

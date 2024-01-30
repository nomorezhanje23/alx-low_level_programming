#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

/**
 * add - addition for two numbers
 * @a: number one
 * @b: number two
 * Return: result output as an int
 */

int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - the subtraction process
 * @a: number one
 * @b: number two
 * Return: result output as an int
 */

int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - the multiplication two nums
 * @a: number one
 * @b: number two
 * Return: result output of operation
 */

int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - this divides two
 * @a: number one
 * @b: number two
 * Return: result output of operation
 */

int div(int a, int b)
{
	return (a / b);
}

/**
 * mod - returns the remainder when a number is divided by another.
 * @a: number one
 * @b: number two
 * Return: result output of operation
 */

int mod(int a, int b)
{
	return (a % b);
}

#include <unistd.h>

/**
 * main - A program that prints anew line to a tandard error
 * Return: 1when the program is true and successful
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);
}

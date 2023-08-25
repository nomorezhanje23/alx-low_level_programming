#include <stdio.h>

void begin(void) __attribute__ ((constructor));

/**
 * begin - prints a sentence before the mai is executed
 * function will then be executed
 */
void begin(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

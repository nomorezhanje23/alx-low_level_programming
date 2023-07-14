#include <stlib.h>
#include <time.h>
#include <stdio.h>
/**
  * main - Entry point
  * Return: 0 always when the code is true
  */
int main(void)
{
int n;
int lastnum;

srand(time(0));
n = rand() - RAND_MAX / 2;
if (lastnum > 5)
{
printf("Last digit of %d and is greater than 5\n", n, lastnum);
}
else if (lastnum == 0)
{
printf("Last digit of %d is and is 0\n", n, lastnum);
}
else if (lastnum < 6 && lastnum != 0)
{
printf("Last digit of %d is %d and is less tham 6 and not 0\n", n, lastnum);
}
return (0);
}

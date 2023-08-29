#include "lists.h"

/**
 * print_listint - prints the entire elements of the linked list
 * @h: links list to be printed
 * Return: the num of nodz
 */
size_t print_listint(const listint_t *h)
{
size_t nx = 0;

while (h)
{
printf("%d\n", h->n);
nx++;
h = h->next;
}
return (nx);
}

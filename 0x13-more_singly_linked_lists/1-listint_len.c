#include "lists.h"

/**
 * listint_len - gives the number of elements in the list
 * @h: pointer to the head
 * Return: number of elements of the list
 */
size_t listint_len(const listint_t *h)
{
size_t cwt = 0;

while (h != NULL)
{
cwt++;
h = h->next;
}
return (cwt);
}

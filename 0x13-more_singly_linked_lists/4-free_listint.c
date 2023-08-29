#include "lists.h"

/**
 * free_listint - frees the list.
 * @head: pointer to the head
 * The function frees nodes in the list for memory
 */

void free_listint(listint_t *head)
{
listint_t *car = head;
while (car != NULL)
{
listint_t *am = car;
car = car->next;
free(am);
}
}

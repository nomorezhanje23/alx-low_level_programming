#include "lists.h"

/**
 * free_listint2 - Frees the list and sets the head to NULL.
 * @head: pointer to the head of list
 * this code frees the nodes, realise the memory and sets head
 */

void free_listint2(listint_t **head)
{
listint_t *mnt = *head;

while (mnt != NULL)
{
listint_t *li = mnt;
mnt = mnt->next;
free(li);
}
*head = NULL;
}

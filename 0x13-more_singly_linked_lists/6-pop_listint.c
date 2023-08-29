#include "lists.h"

/**
 * pop_listint - will delete the head node of list
 * @head: pointer to head of the list
 * Return:data of deleted head node, or 0 if the list has nothing
 */

int pop_listint(listint_t **head)
{
listint_t *lum;
int p;
if (!head || !*head)
{
return (0);
}

p = (*head)->n;
lum = (*head)->next;
free(*head);
*head = lum;

return (p);
}

#include "lists.h"

/**
 * add_nodeint_end - adds a n_node at the end of the  list
 * @head: pointer to pointer to the head of the list
 * @n: value added to the n_node
 * Return: address of the new element, or NULL if unsuccessful
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *nw;
listint_t *well = *head;

nw = malloc(sizeof(listint_t));
if (!nw)
return (NULL);

nw->n = n;
nw->next = NULL;

if (*head == NULL)
{
*head = nw;
return (nw);
}
while (well->next)
well = well->next;

well->next = nw;

return (nw);
}

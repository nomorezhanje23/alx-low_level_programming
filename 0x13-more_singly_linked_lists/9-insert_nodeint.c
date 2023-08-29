#include "lists.h"

/**
 * insert_nodeint_at_index - this inserts a new node into the list
 * @head: pointer to the head
 * @idx: index where the n_node will be added
 * @n: value to be added
 * Return: NULL if  unsucessfull or the address of the n_node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int a;
listint_t *nw;
listint_t *lum = *head;
nw = malloc(sizeof(listint_t));
if (!nw || !head)
return (NULL);

nw->n = n;
nw->next = NULL;
if (idx == 0)
{
nw->next = *head;
*head = nw;
return (nw);
}

for (i = 0; lum && a < idx; a++)
{
if (a == idx - 1)
{
nw->next = lum->next;
lum->next = nw;
return (nw);
}

else
lum = lum->next;
}
return (NULL);
}

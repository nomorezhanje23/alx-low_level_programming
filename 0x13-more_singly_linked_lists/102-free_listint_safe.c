#include "lists.h"

/**
 * free_listint_safe - this frees a linked list
 * @h: pointer to the head of the list
 * Return: the size of the list on sucess that was liberated
 */

size_t free_listint_safe(listint_t **h)
{
listint_t *sw = *h, *ft = *h;
size_t cnt = 0;

while (ft != NULL && ft->next != NULL)
{
sw = sw->next;
ft = ft->next->next;

if (sw == ft)
{
sw = *h;
while (sw != ft)
{
sw = sw->next;
ft = ft->next;
}
while (ft->next != sw)
{
ft = ft->next;
}
ft->next = NULL;
break;
}
}
while (*h != NULL)
{
listint_t *temp = *h;
*h = (*h)->next;
free(temp);
cnt++;
}
return (cnt);
}

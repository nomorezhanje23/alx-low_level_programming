#include "lists.h"

/**
 * free_listint_safe - this frees a linked list
 * @h: pointer to the head of the list
 * Return: the size of the list on sucess that was liberated
 */

size_t free_listint_safe(listint_t **h)
{
listint_t *slow = *h, *fast = *h;
size_t count = 0;

while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
slow = *h;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
while (fast->next != slow)
{
fast = fast->next;
}
fast->next = NULL;
break;
}
}
while (*h != NULL)
{
listint_t *temp = *h;
*h = (*h)->next;
free(temp);
count++;
}
return (count);
}

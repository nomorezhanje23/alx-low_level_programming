#include "lists.h"

/**
 * get_nodeint_at_index - this returns nth node of the list
 * @head: Pointer to  head
 * @index: Index of the node to be found
 * Return: the pointer to  nth node,
 * or if the node does not exist return NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int k = 0;

while (head != NULL)
{
if (k == index)
{
return (head);
}
k++;
head = head->next;
}
return (NULL);
}

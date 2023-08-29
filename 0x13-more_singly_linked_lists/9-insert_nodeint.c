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
listint_t *n_node = malloc(sizeof(listint_t));

if (n_node == NULL)
{
return (NULL);
}

n_node->n = n;

if (idx == 0)
{
n_node->next = *head;
*head = n_node;
return (n_node);
}

listint_t *cnt = *head;
for (unsigned int i = 0; i < idx - 1; i++)
{
if (cnt == NULL)
{
free(n_node);
return (NULL);
}
cnt = cnt->next;
}

if (cnt == NULL)
{
free(n_node);
return (NULL);
}

n_node->next = cnt->next;
cnt->next = n_node;

return (n_node);
}

#include "lists.h"

/**
 * add_nodeint - adds a n_node in front of the list
 * @head: pointer to  pointe the head of the list
 * @n: value to be added to n_node
 * Return: address of the new element, or NULL if unsucessful
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *n_node = malloc(sizeof(listint_t));

if (n_node == NULL)
{
return (NULL);
}

n_node->n = n;
n_node->next = *head;
*head = n_node;

return (n_node);
}

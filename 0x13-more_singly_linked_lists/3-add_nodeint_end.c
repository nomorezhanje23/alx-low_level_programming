#include "lists.h"

/**
 * add_nodeint_end - adds a n_node at the end of the  list
 * @head: pointer to pointer to the head of the list
 * @n: value added to the n_node
 * Return: address of the new element, or NULL if unsuccessful
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *n_node = malloc(sizeof(listint_t));

if (n_node == NULL)
{
return (NULL);
}

n_node->n = n;
n_node->next = NULL;

if (*head == NULL)
{
*head = n_node;
}
else
{
listint_t *nw = *head;
while (nw->next != NULL)
{
nw = nw->next;
nw->next = n_node;
}
return (n_node);
}

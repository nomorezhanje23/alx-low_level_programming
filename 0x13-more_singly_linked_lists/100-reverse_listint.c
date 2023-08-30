#include "lists.h"

/**
 * reverse_listint - this reverses the linked list
 * @head: pointer to first node
 * Return: the result  pointer to the first node for new list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *next = NULL;
listint_t *prev = NULL;

while (*head)
{
next = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = next;
}

*head = prev;

return (*head);
}

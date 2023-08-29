#include "lists.h"

/**
 * reverse_listint - this reverses the list
 * @head: pointer to first node
 * Return: the result  pointer to the first node for new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *bfr = NULL;
	listint_t *aft = NULL;

	while (*head)
	{
		aft = (*head)->aft;
		(*head)->aft = bfr;
		bfr = *head;
		*head = aft;
	}

	*head = bfr;

	return (*head);
}

#include "lists.h"

/**
 * reverse_listint - this reverses the list
 * @head: pointer to first node
 * Return: the result  pointer to the first node for new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *nex = NULL;
	listint_t *pre = NULL;

	while (*head)
	{
		nex = (*head)->nex;
		(*head)->nex = pre;
		pre = *head;
		*head = nex;
	}

	*head = pre;

	return (*head);
}

#include "lists.h"

/**
 * free_dlistint - this frees a dlistint_t list
 * @head: head pointer of the list
 * Return: nothing
 **/
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
	return;

	while (head->next)
	{
	head = head->next;
	free(head->prev);
	}
	free(head);
}

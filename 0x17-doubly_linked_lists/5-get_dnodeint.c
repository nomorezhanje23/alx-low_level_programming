#include "lists.h"

/**
 * get_dnodeint_at_index - this returns nth node of dlistint_t linked list
 * @head: head pointer of the list
 * @index: node index to search for, starting from 0
 * Return: null or nth node
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int size;
	dlistint_t *tmp;

	size = 0;
	if (head == NULL)
	return (NULL);

	tmp = head;
	while (tmp)
	{
	if (index == size)
	return (tmp);
	size++;
	tmp = tmp->next;
	}
	return (NULL);
}

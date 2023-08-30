#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - takes care of the number of unique nodes in a list
 * @head: pointer to the head of the list
 * Return: 0 when the list is not looped or number of unique nodes
 */
size_t looped_listint_len(const listint_t *head)
{
const listint_t *small, *big;
size_t nodes = 1;

if (head == NULL || head->next == NULL)
return (0);

small = head->next;
big = (head->next)->next;

while (big)
{
if (small == big)
{
small = head;
while (small != big)
{
nodes++;
small = small->next;
big = big->next;
}

small = small->next;
while (small != big)
{
nodes++;
small = small->next;
}

return (nodes);
}

small = small->next;
big = (big->next)->next;
}

return (0);
}

/**
 * print_listint_safe - this prints a  list safely accordingly
 * @head: pointer to the head of the list
 * Return: this is the number of nodes in the entire list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, i = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (i = 0; i < nodes; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}

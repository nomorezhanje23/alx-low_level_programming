#include "lists.h"

/**
 * find_listint_loop - this finds the loop in the list
 * @head: linked list that is being searched
 * Return: the address at the beginning of the node or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *sw = head;
	listint_t *ft = head;

	if (!head)
		return (NULL);

	while (sw && ft && ft->next)
	{
		ft = ft->next->next;
		sw = sw->next;
		if (ft == sw)
		{
			sw = head;
			while (sw != ft)
			{
				sw = sw->next;
				ft = ft->next;
			}
			return (ft);
		}
	}

	return (NULL);
}

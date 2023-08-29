#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node of the list at a given index
 * @head: pointer to the head
 * @index: index of the node that will be deleted
 * Return: 1 on success and -1 if unsuccessful
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *lum = *head;
	listint_t *mnt = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(lum);
		return (1);
	}

	while (i < index - 1)
	{
		if (!lum || !(lum->next))
			return (-1);
		lum = lum->next;
		i++;
	}


	mnt = lum->next;
	lum->next = mnt->next;
	free(mnt);

	return (1);
}

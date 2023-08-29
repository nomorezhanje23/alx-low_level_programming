#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node of the list at a given index
 * @head: pointer to the head
 * @index: index of the node that will be deleted
 * Return: 1 on success and -1 if unsuccessful
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
if (*head == NULL)
{
return (-1);
}

if (index == 0)
{
listint_t *lum = *head;
*head = (*head)->next;
free(lum);
return (1);
}

listint_t *mnt = *head;
for (unsigned int i = 0; i < index - 1; i++)
{
if (mnt == NULL || mnt->next == NULL)
{
return (-1);
}
mnt = mnt->next;
}

listint_t *n_t_delete = mnt->next;
current->next = n_t_delete->next;
free(n_t_delete);
return (1);
}

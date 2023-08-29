#include "lists.h"

/**
 * pop_listint - will delete the head node of list
 * @head: pointer to head of the list
 * Return: mnu -> data of deleted head node, or 0 if the list has nothing
 */

int pop_listint(listint_t **head)
{
if (*head == NULL)
{
return (0);
}
int mnu = (*head)->n;
listint_t *lm = *head;
*head = (*head)->next;
free(lm);

return (mnu);

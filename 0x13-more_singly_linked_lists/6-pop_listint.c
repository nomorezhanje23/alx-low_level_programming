#include "lists.h"

/**
 * pop_listint - will delete the head node of list
 * @head: pointer to head of the list
 * Return: poop the data of deleted head node, or 0 if the list has nothing
 */

int pop_listint(listint_t **head)
{
listint_t *lm;
int poop;
if (!head || !*head)
return (0);
poop = (*head)->n;
lm = (*head)->next;
free(*head);
*head = lm;

return (poop);

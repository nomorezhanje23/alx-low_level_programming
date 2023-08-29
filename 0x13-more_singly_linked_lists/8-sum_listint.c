#include "lists.h"

/**
 * sum_listint - brings the sum of everthing in the list
 * @head: pointer to the head
 * Return: the sum of the whole code, or 0 if empty
 */

int sum_listint(listint_t *head)
{
int all = 0;

while (head != NULL)
{
all += head->n;
head = head->next;
}
return (all);
}

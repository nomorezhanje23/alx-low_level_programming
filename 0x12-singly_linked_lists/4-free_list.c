#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */

void free_list(list_t *head)
{
while (head != NULL)
{
list_t *dis = head;
head = head->next;
free(dis->str);
free(dis);
}
}

#include "monty.h"
/**
 * stackfree - frees stack_t
 * @head: pointer to head
 * Return: void
 */
void stackfree(stack_t *head)
{
	stack_t *nx;

	if (!head)
		return;
	nx = head;
	while (nx)
	{
		head = nx;
		nx = head->next;
		free(head);
	}

}

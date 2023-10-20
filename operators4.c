#include "monty.h"
/**
 * pstr - prints string
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	temp = *stack;
	(void)line_n;
	while (temp != NULL && temp->n != 0 && isprint(temp->n))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");

}

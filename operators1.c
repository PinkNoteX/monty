#include "main.h"
void push(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp, *n;
	int value;
	char *parg;

	parg = strtok(NULL, "\n\t ");
	if (!intcheck(parg))
		fprintf(stdout, "L%u: usage: push integer\n", line_n), exit(EXIT_FAILURE);
	value = atoi(parg);
	n = malloc(sizeof(stack_t));
	if (n == NULL)
		fprintf(stdout, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	n->n = value;
	n->next = NULL;
	n->prev = NULL;
	if ((*stack) == NULL)
		*stack = n;
	else
	{
		if (SandQChecker == 0)
		{
			tmp = *stack;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = n;
			tmp->prev = tmp;
		}
		else
		{
			(*stack)->prev = n;
			n->next = *stack;
			*stack = n;
		}
	}
}
void pall(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;
	(void)line_n;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
void stack(stack_t **stack, unsigned int line_n)
{
	(void)line_n;
	(void)stack;
	SandQChecker = 1;
}
void queue(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
	SandQChecker = 0;
}

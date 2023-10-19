#include "monty.h"
/**
 * push - pushes integar into stack be it in queue or stack mode
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
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
/**
 * pall - prints the stack
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
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
/**
 * stack - checks if in LIFO mode
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void stack(stack_t **stack, unsigned int line_n)
{
	(void)line_n;
	(void)stack;
	SandQChecker = 1;
}
/**
 * queue - checks if in FIFO mode
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void queue(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
	SandQChecker = 0;
}
/**
 * freeline - frees line if not NULL
 * @line: line to be freed
 * Return: void
 */
void freeline(char *line)
{
	if (line)
		free(line);
}
/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_n)
{
        (void)line_n;

        if (*stack == NULL)
		fprintf(stdout, "L%d: can't pint, stack empty\n", line_n), exit(EXIT_FAILURE);
	printf("%d\n", (*stack)->n);
}


#include "monty.h"
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
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the last input to stack
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
/**
 * swap - swaps the last two integars
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_n)
{
	int temp;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

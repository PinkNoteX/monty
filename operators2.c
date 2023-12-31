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

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * add - adds the last two elements of the stack
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void add(stack_t **stack, unsigned int line_n)
{
	int thesum;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	thesum = (*stack)->next->n + (*stack)->n;
	pop(stack, line_n);
	(*stack)->n = thesum;
}
/**
 * nop - it does nothing
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}

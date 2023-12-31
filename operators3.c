#include "monty.h"
/**
 * sub - substracts the last two inputed elements
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_n)
{
	int tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n - (*stack)->n;
	pop(stack, line_n);
	(*stack)->n = tmp;
}
/**
 * divide - divides the two elements at the head of the stack
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_n)
{
	int tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n / (*stack)->n;
	pop(stack, line_n);
	(*stack)->n = tmp;
}
/**
 * mul - multiplies the two elements at the head of the stack
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_n)
{
	int tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n * (*stack)->n;
	pop(stack, line_n);
	(*stack)->n = tmp;
}
/**
 * modu - preforms mod operator
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void modu(stack_t **stack, unsigned int line_n)
{
	int tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n % (*stack)->n;
	pop(stack, line_n);
	(*stack)->n = tmp;
}
/**
 * pchar - outputs the char at the head
 * @stack: the stack
 * @line_n: the line number the read is currently at
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_n)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	if (!isprint((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}


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
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n), exit(EXIT_FAILURE);
	printf("%d\n", (*stack)->n);
}

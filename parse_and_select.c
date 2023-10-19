#include "monty.h"

/**
 * intcheck - check if given str is int or not
 * @str: int to check
 * Return: 1 or 0
 */
int intcheck(char *str)
{
	int x = 0;

	if (str == NULL)
		return (0);
	if (*str == '-')
		x++;
	while (str[x])
	{
		if (isdigit(str[x]) == 0)
			return (0);
		x++;
	}
	return (1);
}
/**
 * opcodeg - gets opcode
 * @str: line to get from
 * Return: opecode
 */
char *opcodeg(char *str)
{
	char *opcode;

	opcode = strtok(str, "\n\t ");
	return (opcode);

}
/**
 * fselector - parses the given line and handles the function given
 * @line: line to be parsed and checked
 * Return: void
 */
instruction_t *fselector(char *line)
{
	instruction_t *inst;
	char *opcode;

	inst = malloc(sizeof(*inst));
	if (inst == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	opcode = opcodeg(line);
	inst->opcode = opcode;
	inst->f = NULL;

	if (inst->opcode != NULL)
	{
		if (strcmp(inst->opcode, "push") == 0)
			inst->f = push;
		if (strcmp(inst->opcode, "pall") == 0)
			inst->f = pall;
		if (strcmp(inst->opcode, "stack") == 0)
			inst->f = stack;
		if (strcmp(inst->opcode, "queue") == 0)
			inst->f = queue;
		if (strcmp(inst->opcode, "pint") == 0)
			inst->f = pint;
		if (strcmp(inst->opcode, "pop") == 0)
			inst->f = pop;
		if (strcmp(inst->opcode, "swap") == 0)
			inst->f = swap;
		if (strcmp(inst->opcode, "add") == 0)
			inst->f = add;
	}
	return (inst);
}

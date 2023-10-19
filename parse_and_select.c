#include "monty.h"

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
char *opcodeg(char *str)
{
	char *opcode;

	opcode = strtok(str, "\n\t ");
	return (opcode);

}
instruction_t *fselector(char *line)
{
	instruction_t *inst;
	char *opcode;

	inst = malloc(sizeof(*inst));
	if (inst == NULL)
		fprintf(stdout, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	opcode = opcodeg(line);
	inst->opcode = opcode;
	inst->f = NULL;

	if (inst->opcode != NULL)
	{
		if (strcmp(inst->opcode, "push") == 0)
			inst->f = push;
		if (strcmp(inst->opcode, "pall") == 0)
                        inst->f = pall;
	}
	return (inst);
}

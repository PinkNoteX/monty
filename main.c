#include "monty.h"
#include <stdio.h>
/**
 * main - main function for monty
 * @argc: number of args
 * @argv: pointer to args
 * Return: 0 or exit value
 */
int main(int argc, char **argv)
{
	FILE *in;
	unsigned int line_n = 0;
	ssize_t ggetline = 1;
	size_t getline_size = 0;
	char *line = NULL;
	stack_t *head = NULL;
	instruction_t *inst = NULL;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	SandQChecker = 1, in = fopen(argv[1], "r");
	if (in == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		ggetline = getline(&line, &getline_size, in);
		if (ggetline == -1)
			break;
		line_n++;
		inst = fselector(line);
		if (inst->opcode == NULL || inst->opcode[0] == '#')
		{
			free(inst), freeline(line);
			line = NULL;
			continue; }
		if (inst->f != NULL)
			inst->f(&head, line_n);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, inst->opcode);
			freeline(line);
			if (head)
				stackfree(head);
			free(inst);
			fclose(in);
			exit(EXIT_FAILURE); }
		freeline(line);
		line = NULL;
		free(inst); }
	freeline(line), stackfree(head), fclose(in);
	return (0); }

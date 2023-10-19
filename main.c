#include "main.h"
int main(int argc, char **argv)
{
	FILE *in;
	unsigned int line_n = 0;
	size_t getline_size = 0;
	ssize_t ggetline;
	char *line = NULL;
	stack_t *head = NULL;
	instruction_t *inst = NULL;

	if (argc != 2)
		fprintf(stdout, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	in = fopen(argv[1], "r");
	if (in == NULL)
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		ggetline = getline(&line, &getline_size, in);
		line_n++;
		inst = fselector(line);
		if (ggetline == -1)
			break;
		if (inst->opcode == NULL)
		{
			free(inst);
			if (line)
				free(line);
			line = NULL;
			continue;
		}
		if (inst->f != NULL)
			inst->f(&head, line_n);
		else
		{
			fprintf(stdout, "L%d: unknown instruction %s\n", line_n, inst->opcode);
			if (line)
				free(line);
			if (head)
				//free stack..
			free(inst);
			fclose(in);
			exit(EXIT_FAILURE);
		}
		if (line)
			free(line);
		line = NULL;
		free(inst);
	}
	if (line)
		free(line);
	// free stack
	fclose(in);
	return (0);
}

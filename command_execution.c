#include "monty.h"
/**
 * command_execution - execute the command.
 * @command_arg : array of the command and it's argument.
 * @line_number : number of command line in the file.
 *
 * Return: Void
 */
void command_execution(char *command_arg[], int line_number)
{
	int arg = -1;
	stack_t *ptr;
	instruction_t opcode_fun[] = {
			{"push", push},
			{"pall", pall}
		};

	if (strcmp(command_arg[0], "push") == 0)
	{
		if (strcmp(command_arg[2], "None") == 0)
		{
			arg = atoi(command_arg[1]);
			if (arg == 0 && (strcmp(command_arg[1], "0") != 0))
			{
				fprintf(stderr, "L%d: usage: push integer.\n", line_number);
				exit(EXIT_FAILURE);
			}
			ptr = malloc(sizeof(stack_t));
			if (ptr == NULL)
			{
				fprintf(stderr, "Error: malloc failed");
				exit(EXIT_FAILURE);
			}
			ptr->n = arg;
			push(&ptr, line_number);
		}
	}
	else if (strcmp(command_arg[0], opcode_fun[1].opcode) == 0)
	{
		if (strcmp(command_arg[1], "None") == 0)
			opcode_fun[1].f(&top, line_number);
	}
	else
	{
		if (strcmp(command_arg[0], "None") != 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command_arg[0]);
			exit(EXIT_FAILURE);
		}
	}
}

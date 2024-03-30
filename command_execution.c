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
	int arg = -1, i, check = 0;
	stack_t *ptr;
	instruction_t opcode_fun[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"sub", sub}
		};

	if (strcmp(command_arg[0], "push") == 0)
	{
		if (strcmp(command_arg[2], "None") == 0)
		{
			arg = my_atoi(command_arg[1]);
			if (arg == 1 && strcmp(command_arg[1], "1") != 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
	else
	{
		for (i = 1; i < 7; i++)
		{
			if (strcmp(command_arg[0], opcode_fun[i].opcode) == 0)
			{
				if (strcmp(command_arg[1], "None") == 0)
				{
					check += 1;
					opcode_fun[i].f(&top, line_number);
				}
			}
		}
		if (strcmp(command_arg[0], "None") != 0 && check == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command_arg[0]);
			exit(EXIT_FAILURE);
		}
	}
}

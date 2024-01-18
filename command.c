#include "monty.h"
/**
 * command - choose the command to be executed
 * @str : command to be execute
 * @line_number : number of the command line
 *
 * Return: void
 */
void command(char **str, unsigned int line_number)
{
	instruction_t op_code[3] = {
		{"push", push},
		{"pall", display},
		{NULL, NULL}};
	int i, y = 0;

	for (i = 0; i < 2; i++)
	{
		if ((strcmp(str[0], op_code[i].opcode)) == 0)
		{
			op_code[i].f(&head, line_number);
			y += 1;
		}
	}
	if (y == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str[0]);
		exit(EXIT_FAILURE);
	}
}

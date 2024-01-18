#include "monty.h"
/**
 * command - choose the command to be executed
 * @str : command to be execute
 * @line_number : number of the command line
 *
 * Return: void
 */
void command(char **str, unsigned int line_number);
void command(char **str, unsigned int line_number)
{
	instruction_t op_code[3] = {
		{"push", push},
		{"pall", display},
		{NULL, NULL}};
	stack_t *ptr;
	char *c = str[1];
	int i, len = 0, y = 0, x = 0;

	if (*c >= 48 && *c <= 57)
	{
		x += 1;
	}
	while (str[len])
	{
		len += 1;
	}
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (str[1] != NULL)
	{
		ptr->n = atoi(str[1]);
	}
	for (i = 0; i < 2; i++)
	{
		if ((strcmp(str[0], op_code[i].opcode)) == 0)
		{
			if ((i == 0 && len == 1) || (i == 0 && x == 0))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			op_code[i].f(&ptr, line_number);
			y += 1;
		}
	}
	if (y == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str[0]);
		exit(EXIT_FAILURE);
	}
}

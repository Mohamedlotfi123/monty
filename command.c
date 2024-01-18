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
	stack_t *ptr;
	int i;
	(void)line_number;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
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
			op_code[i].f(&ptr, line_number);
		}
	}
}

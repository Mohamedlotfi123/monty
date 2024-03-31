#include "monty.h"
/**
 * pchar - prints the char at the top of the stack.
 * @stack : pointer of the pointer to the top.
 * @line_number : command line number.
 *
 * Return: Void.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if ((value >= 65 && value <= 90) || (value >= 97 && value <= 122))
		printf("%c\n", value);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

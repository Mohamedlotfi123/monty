#include "monty.h"
/**
 * pint - print the value at the top of the stack.
 * @stack : pointer of the pointer to the top.
 * @line_number : number of the command line.
 *
 * Return: Void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

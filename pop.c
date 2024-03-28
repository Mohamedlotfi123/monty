#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack : pointer of the pointer to the top.
 * @line_number : command line number.
 *
 * Return: Void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

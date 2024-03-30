#include "monty.h"
/**
 * sub - add the top two elements of the stack.
 * @stack : pointer of the pointer to the top.
 * @line_number : command line number.
 *
 * Return: Void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sub += tmp->n - (tmp->next)->n;
	if (sub < 0)
		sub = sub * -1;
	(tmp->next)->n = sub;
	*stack = (*stack)->next;
	free(tmp);
}

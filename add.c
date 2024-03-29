#include "monty.h"
/**
 * add - add the top two elements of the stack.
 * @stack : pointer of the pointer to the top.
 * @line_number : command line number.
 *
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *tmp;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sum += tmp->n + (tmp->next)->n;
	(tmp->next)->n = sum;
	*stack = (*stack)->next;
	free(tmp);
}

#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element of the stack
 * 	by the top element of the stack.
 * @stack : pointer of the pointer to the top.
 * @line_number : command line number.
 *
 * Return: Void.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	result = (tmp->next)->n % tmp->n;
	*stack = tmp->next;
	(*stack)->n = result;
	free(tmp);
}

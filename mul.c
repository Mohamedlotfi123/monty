#include "monty.h"
/**
 * mul - multiply the second top element of the stack with top element.
 * @stack : pointer of the pointer to the top element.
 * @line_number : command line number.
 *
 * Return: void.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	result = tmp->n * (tmp->next)->n;
	*stack = (*stack)->next;
	(*stack)->n = result;
	free(tmp);
}

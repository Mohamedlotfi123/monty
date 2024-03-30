#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack : pointer of the pointer to the top.
 * @line_number : command line number.
 *
 * Return: Void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}

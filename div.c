#include "monty.h"
/**
 * divide - divides the second top element of the stack by the top element.
 * @stack : pointer of the pointer to the top.
 * @line_number : command line number.
 *
 * Return: Void.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	result = (tmp->next)->n / tmp->n;
	*stack = tmp->next;
	(*stack)->n = result;
	free(tmp);
}

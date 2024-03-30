#include "monty.h"
/**
 * free_stack - free the stack.
 * @stack : pointer of the pointer to the top.
 *
 * Return: Void
 */
void free_stack(stack_t **stack)
{
	stack_t *p;

	while (*stack != NULL)
	{
		p = *stack;
		*stack = (*stack)->next;
		free(p);
	}
}

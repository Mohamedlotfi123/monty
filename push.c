#include "monty.h"
/**
 * push - insert element into the stack.
 * @ptr : element to add.
 * @line_number : number of the command.
 *
 * Return: Void.
 */
void push(stack_t **ptr, unsigned int line_number)
{
	(void)line_number;

	if (top == NULL)
	{
		(*ptr)->next = NULL;
		(*ptr)->prev = NULL;
		top = *ptr;
	}
	else
	{
		(*ptr)->next = top;
		(*ptr)->prev = NULL;
		top->prev = *ptr;
		top = *ptr;
	}
}

#include "monty.h"
/**
 * push - add element to the stack
 * @stack : pointer to pointer to the node
 * @line_number : number of command line
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (head == NULL)
	{
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
		head = *stack;
	}
	else
	{
		(*stack)->next = head;
		(*stack)->prev = NULL;
		head->prev = *stack;
		head = *stack;
	}
}

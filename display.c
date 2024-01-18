#include "monty.h"
/**
 * display - print the element of the stack
 * @stack : pointer to the stack
 * @line_number : number of line
 *
 * Return: Void;
 */
void display(stack_t **stack, unsigned int line_number)
{
	stack_t *p;
	(void)stack;
	(void)line_number;

	p = head;
	if (head == NULL)
	{
		fprintf(stderr, "Underflow: The stack is empty");
	}
	else
	{
		while (p != NULL)
		{
			printf("%d\n", p->n);
			p = p->next;
		}
	}
}

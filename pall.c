#include "monty.h"
/**
 * pall - print all elements.
 * @stack : head of the node.
 * @line_number : number of command line.
 *
 * Return: Void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("empty stack!");
	}
	else
	{
		p = *stack;
		while (p != NULL)
		{
			printf("%d\n", p->n);
			p = p->next;
		}
	}
}

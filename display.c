#include "monty.h"
/**
 * display - print the element of the stack
 * @head : pointer to the top of a stack
 * @line_number : number of line
 *
 * Return: Void;
 */
void display(stack_t **head, unsigned int line_number)
{
	stack_t *p;
	(void)line_number;

	p = *head;
	if (p != NULL)
	{
		while (p != NULL)
		{
			printf("%d\n", p->n);
			p = p->next;
		}
	}
}

#include "monty.h"
/**
 * pstr - prints the string at the top of the stack.
 * @stack : pointer of the pointer to the top.
 * @line_number : command line number.
 *
 * Return: Void.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *ptr;
	(void)line_number;

	if (*stack == NULL)
		printf("\n");
	else
	{
		ptr = *stack;
		while (ptr != NULL)
		{
			value = ptr->n;
			if ((value >= 65 && value <= 90) || (value >= 97 && value <= 122))
				printf("%c", value);
			else
				break;
			ptr = ptr->next;
		}
		printf("\n");
	}
	
}

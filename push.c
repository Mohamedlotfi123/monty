#include "monty.h"
/**
 * push - add element to the stack
 * @stack : pointer to pointer to the node
 * @line_number : number of command line
 *
 * Return: Void
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;
	int x;

	if (*arg >= 48 && *arg <= 57)
	{
		x = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	ptr->n = x;
	if (*head == NULL)
	{
		ptr->next = NULL;
		ptr->prev = NULL;
		*head = ptr;
	}
	else
	{
		ptr->next = *head;
		ptr->prev = NULL;
		(*head)->prev = ptr;
		*head = ptr;
	}
}

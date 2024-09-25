#include "monty.h"

/**
  *push -function that pushes an element to the stack.
  *@stack: double pointer to the top(head) of the stack
  *@line_number: line number in the bytecode file
  *@n: inyteger to be pushed to the stack
  */

void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

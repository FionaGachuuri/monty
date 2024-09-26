#include "monty.h"

/**
  *pop_op -function that removes the top element of the stack.
  *@stack: double pointer to the head of the stack
  *@line_number: current line number inthe bytecode file.
  */

void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current_top = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(current_top);
}

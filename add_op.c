#include "monty.h"

/**
  *add_op -function that adds two elements of the stack
  *stack: double pointer to the head of the stack
  *@line_number: current line number in the bytecode file
  */

void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	current_top = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(current_top);
}


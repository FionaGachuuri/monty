#include "monty.h"

/**
  *sub_op -function that subtracts the top 
  *elemeent of the stack.
  *@stack: double pointer to the head (top) of the stack
  *@line_number: current line ion the bytecode file.
  */

void sub_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;

	current_top = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(current_top);
}

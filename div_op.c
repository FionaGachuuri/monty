#include "monty.h"

/**
  *div_op: function that divides the second top element
  *of the stack by the top element of the stack
  *@stack: double pointer to the head of the stack
  *@line_number: current line of the bytecode file
  */

void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;

	current_top = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(current_top);
}





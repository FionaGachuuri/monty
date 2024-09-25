#include "monty.h"

/**
  *pall -function that prints all the values in ths stack
  *starting from the top 
  *@stack: double pointer to the top(head) of the stack
  *line_number: line number in the bytecode
  */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	(void)line_number;
	current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

#include "monty.h"

/**
  *free_stack -function that frees all the stack
  *@stack: pointer to the top of the stack
  */
 void free_stack(stack_t *stack)
{
	stack_t *current_node;

	while (stack != NULL)
	{
		current_node = stack;
		stack = stack->next;
		free(current_node);
	}
}

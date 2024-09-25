#include "monty.h"

/**
  *valid_number -function that checks if a string rep a valid integer.
  *@str: string to be checked.
  *
  *Return: 1 if its a valid integer, or 0 if otherwise.
  */

int valid_number(const char *arg)
{
	if (arg == NULL || *arg == '\0')
	{
		return (0);
	}
	if (*arg == '-' || *arg == '+')
	{
		arg++;
	}
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
		{
			return (0);
		}
			arg++;
	}
	return (1);
}

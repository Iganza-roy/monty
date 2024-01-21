#include "monty.h"

/**
 * p_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void p_str(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	int ascii_val;
	stack_t *tmpy;

	if (stack == NULL || *stack == NULL)
	{
		putchar('\n');
		return;
	}

	tmpy = *stack;
	while (tmpy != NULL)
	{
		ascii_val = tmpy->n;
		if (ascii_val <= 0 || ascii_val > 127)
			break;
		putchar(ascii_val);
		tmpy = tmpy->next;
	}
	putchar('\n');
}

#include "monty.h"

/**
 * p_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void p_char(stack_t **stack, unsigned int l_num)
{
	int ascii_val;
	if (stack == NULL || *stack == NULL)
		strerr(11, l_num);

	ascii_val = (*stack)->n;

	if (ascii_val < 0 || ascii_val > 127)
		strerr(10, l_num);
	putchar(ascii_val);
	putchar('\n');
}

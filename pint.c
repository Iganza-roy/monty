#include "monty.h"

/**
 * pint_me - prints value at the top of stack
 * @top_stack: pointer to top node of stack
 * @line_no: line number of opcode
 */
void pint_me(stack_t **top_stack, unsigned int line_no)
{
	if (top_stack == NULL || *top_stack == NULL)
		pr_more_err(6, line_no);
	printf("%d\n", (*top_stack)->n);
}


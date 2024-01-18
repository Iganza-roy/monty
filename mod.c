#include "monty.h"

/**
 * mod_elem - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void mod_elem(stack_t **stack, unsigned int l_num)
{
	int k;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		pr_more_err(8, l_num, "mod");

	if ((*stack)->n == 0)
		pr_more_err(9, l_num);
	(*stack) = (*stack)->next;
	k = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = k;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

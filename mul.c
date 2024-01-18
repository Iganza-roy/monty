#include "monty.h"

/**
 * mul_elem - multiplies the second top element of the stack with the top element
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.i
 * Return: nothing
 */
void mul_elem(stack_t **stack, unsigned int l_num)
{
	int k;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		pr_more_err(8, l_num, "mul");

	(*stack) = (*stack)->next;
	k = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = k;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

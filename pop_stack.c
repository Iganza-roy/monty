#include "monty.h"

/**
 * pop_stack - removes the top element of the stack..
 * @stack: Pointer to a pointer to the top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void pop_stack(stack_t **stack, unsigned int l_num)
{
	stack_t *tmpy;

	if (stack == NULL || *stack == NULL)
		pr_more_err(7, l_num);

	tmpy = *stack;
	*stack = tmpy->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmpy);
}

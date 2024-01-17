#include "monty.h"

/**
 * swap_elem - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer to the  top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void swap_elem(stack_t **stack, unsigned int l_num)
{
	stack_t *tmpy;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		pr_more_err(8, l_num, "swap");
	tmpy = (*stack)->next;
	(*stack)->next = tmpy->next;
	if (tmpy->next != NULL)
		tmpy->next->prev = *stack;
	tmpy->next = *stack;
	(*stack)->prev = tmpy;
	tmpy->prev = NULL;
	*stack = tmpy;
}

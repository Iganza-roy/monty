#include "monty.h"

/**
 * rotr_stack - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void rotr_stack(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmpy;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpy = *stack;

	while (tmpy->next != NULL)
		tmpy = tmpy->next;

	tmpy->next = *stack;
	tmpy->prev->next = NULL;
	tmpy->prev = NULL;
	(*stack)->prev = tmpy;
	(*stack) = tmpy;
}

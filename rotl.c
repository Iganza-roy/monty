#include "monty.h"

/**
 * rotl_stack - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void rotl_stack(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmpy;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpy = *stack;
	while (tmpy->next != NULL)
		tmpy = tmpy->next;

	tmpy->next = *stack;
	(*stack)->prev = tmpy;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

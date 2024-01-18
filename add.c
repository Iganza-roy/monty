#include "monty.h"

/**
 * add_op - adds top two elements of the stack
 * @top_stack: double pointer to top node of stack
 * @line_no: line number to the opcode
 */
void add_op(stack_t **top_stack, unsigned int line_no)
{
	int total;

	if (top_stack == NULL || *top_stack == NULL || (*top_stack)->next == NULL)
		pr_more_err(8, line_no, "add");

	(*top_stack) = (*top_stack)->next;
	total = (*top_stack)->n + (*top_stack)->prev->n;
	(*top_stack)->n = total;
	free((*top_stack)->prev);
	(*top_stack)->prev = NULL;
}

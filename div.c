#include "monty.h"

/**
 * div_op - divides top two elements of the stack
 * @top_stack: double pointer to top node of stack
 * @line_no: line number to the opcode
 */
void div_op(stack_t **top_stack, unsigned int line_no)
{
	int result;

	if (top_stack == NULL || *top_stack == NULL || (*top_stack)->next == NULL)
		pr_more_err(8, line_no, "div");
	if ((*top_stack)->n == 0)
		pr_more_err(9, line_no);

	(*top_stack) = (*top_stack)->next;
	result = (*top_stack)->n / (*top_stack)->prev->n;
	(*top_stack)->n = result;
	free((*top_stack)->prev);
	(*top_stack)->prev = NULL;
}


#include "monty.h"

/**
 * append_to_stack - Adds a node to the stack.
 * @nnode: Pointer to the new node.
 * @lnum:  line number of of the opcode.
 * Return: nothing
 */
void append_to_stack(stack_t **nnode, __attribute__((unused))unsigned int lnum)
{
	stack_t *tmpy;

	if (nnode == NULL || *nnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nnode;
		return;
	}
	tmpy = head;
	head = *nnode;
	head->next = tmpy;
	tmpy->prev = head;
}

/**
 * pall_stack - prints stack values
 * @top_stack: pointer to top stack
 * @lnum: line number to opcode
 */
void pall_stack(stack_t **top_stack, unsigned int lnum)
{
	stack_t *holder;

	(void) lnum;
	if (tp_stack == NULL)
		exit(EXIT_FAILURE);

	holder = *top_stack;

	while (holder != NULL)
	{
		printf("%d\n", holder->n);
		holder = holder->next;
	}
}

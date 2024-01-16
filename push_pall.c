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

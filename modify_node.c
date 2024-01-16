#include "monty.h"
stack_t *head = NULL;

/**
 * mk_node - Creates a node.
 * @num: number to go inside the node.
 * Return: a pointer to the node, otherwise NULL.
 */
stack_t *mk_node(int num)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_code(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = num;
	return (node);
}

/**
 * node_free - Frees nodes in the stack.
 * Return: nothing
 */
void node_free(void)
{
	stack_t *tmpy;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmpy = head;
		head = head->next;
		free(tmpy);
	}
}

/**
 * add_queue - Adds a node to the queue.
 * @nnode: Pointer to the new node.
 * @ln_num: line number of the opcode.
 * Return: nothing
 */
void add_queue(stack_t **nnode, __attribute__((unused))unsigned int ln_num)
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
	while (tmpy->next != NULL)
		tmpy = tmpy->next;

	tmpy->next = *nnode;
	(*nnode)->prev = tmpy;
}

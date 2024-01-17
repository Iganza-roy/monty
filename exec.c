#include "monty.h"

/**
 * find_op - finds function for opcode
 * @op_code: opcode
 * @passed: argument passed
 * @style: storage format
 * @line_no: line number
 */
void find_op(char *op_code, char *passed, int line_no, int style)
{
	int x;
	int monitor;

	instruction_t op_list[] = {
		{"push", append_to_stack},
		{"pall", pall_stack},
		{"pint", pint_me},
		{"pop", pop_stack},
		{"swap", swap_elem},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return;

	for (monitor = 1, x = 0; op_list[x].opcode != NULL; x++)
	{
		if (strcmp(op_code, op_list[x].opcode) == 0)
		{
			call_op(op_list[x].f, op_code, passed, line_no, style);
			monitor = 0;
		}
	}
	if (monitor == 1)
		err_code(3, line_no, op_code);
}

/**
 * call_op - calls required op
 * @exec: pointer to called function
 * @op: string to opcode
 * @num: string to number
 * @line: no. line to op
 * @style: format specifier
 */
void call_op(op_func exec, char *op, char *pass, int line, int style)
{
	stack_t *node;
	int x, monitor = 1;

	if (strcmp(op, "push") == 0)
	{
		if (pass != NULL && pass[0] == '-')
		{
			pass += 1;
			monitor = -1;
		}
		if (pass == NULL)
		{
			err_code(5, line);
		}
		for (x = 0; pass[x] != '\0'; x++)
		{
			if (isdigit(pass[x]) == 0)
				err_code(5, line);
		}

		node = mk_node(atoi(pass) * monitor);

		if (style == 0)
			exec(&node, line);
		if (style == 1)
			add_queue(&node, line);
	}
	else
	{
		exec(&head, line);
	}
}



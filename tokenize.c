#include "monty.h"

/**
 * tokenize - separates lines to tokens
 * @bf: buffer to line
 * @line_no: line number
 * @style: format specifier
 * Return: 0->stack, 1->queue
 */
int tokenize(char *bf, int line_no, int style)
{
	char *pass, *op_code;
	const char *delimitor = "\n ";

	if (bf == NULL)
		err_code(4);

	op_code = strtok(bf, delimitor);

	if (op_code == NULL)
		return (style);
	pass = strtok(NULL, delimitor);

	if (strcmp(op_code, "queue") == 0)
		return (1);

	if (strcmp(op_code, "stack") == 0)
		return (0);

	find_op(op_code, pass, line_no, style);
	return (style);
}


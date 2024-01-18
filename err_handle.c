#include "monty.h"

/**
 * err_code - prints error message
 * @code_err: Error codes
 */
void err_code(int code_err, ...)
{
	va_list arg;
	char *opr;
	int num_l;

	va_start(arg, code_err);
	switch (code_err)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			num_l = va_arg(arg, int);
			opr = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num_l, opr);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * pr_more_err - error handler
 * @code_err: error codes
 */
void pr_more_err(int code_err, ...)
{
	va_list arg;
	char *opr;
	int num_l;

	va_start(arg, code_err);
	switch (code_err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			num_l = va_arg(arg, unsigned int);
			opr = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num_l, opr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * strerr - error handling
 * @code_err: Error codes
 */
void strerr(int code_err, ...)
{
	va_list arg;
	int num_l;

	va_start(arg, code_err);
	num_l = va_arg(arg, int);
	switch (code_err)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num_l);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num_l);
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}


#include "monty.h"

/**
 * file_open - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void file_open(char *f_name)
{
	FILE *f_des = fopen(f_name, "r");

	if (f_name == NULL || f_des == NULL)
		err_code(2, f_name);

	f_read(f_des);
	fclose(f_des);
}

/**
 * f_read - reads a file
 * @f_des: pointer to file descriptor
 * Return: void
 */

void f_read(FILE *f_des)
{
	int line_num, fmt = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, f_des) != -1; line_num++)
	{
		fmt = parse_line(buffer, line_num, fmt);
	}
	free(buffer);
}

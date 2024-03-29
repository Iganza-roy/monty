#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main file */

int main(int ac, char *av[]);

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* Error handlers */

void err_code(int code_err, ...);
void pr_more_err(int code_err, ...);
void strerr(int code_err, ...);

/* Executables */

void find_op(char *op_code, char *passed, int style, int line_no);
void call_op(op_func exec, char *pass, char *op, int line, int style);

/* Tokenizer */

int tokenize(char *bf, int line_no, int style);

/* Node Manager */

stack_t *mk_node(int num);
void node_free(void);
void add_queue(stack_t **nnode, __attribute__((unused))unsigned int ln_num);

/* File ops */
void file_open(char *f_name);
void f_read(FILE *f_des);

/* stack ops */
void append_to_stack(stack_t **nnode, __attribute__((unused))unsigned int lnum);
void pall_stack(stack_t **top_stack, unsigned int lnum);

/* opcodes */
void pint_me(stack_t **top_stack, unsigned int line_no);
void pop_stack(stack_t **stack, unsigned int l_num);
void swap_elem(stack_t **stack, unsigned int l_num);
void no_work(stack_t __attribute__((unused)) **top_stack, unsigned int __attribute__((unused)) line_no);


/* Math ops */
void add_op(stack_t **top_stack, unsigned int line_no);
void sub_op(stack_t **top_stack, unsigned int line_no);
void div_op(stack_t **top_stack, unsigned int line_no);
void mul_elem(stack_t **stack, unsigned int l_num);
void mod_elem(stack_t **stack, unsigned int l_num);
void rotl_stack(stack_t **stack, __attribute__((unused))unsigned int l_num);
void rotr_stack(stack_t **stack, __attribute__((unused))unsigned int l_num);

/* printin */
void p_char(stack_t **stack, unsigned int l_num);
void p_str(stack_t **stack, __attribute__((unused))unsigned int l_num);
#endif

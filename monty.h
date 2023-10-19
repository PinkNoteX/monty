#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdio.h>
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
extern int SandQChecker;
int SandQChecker;
void stackfree(stack_t *head);
instruction_t *fselector(char *line);
char *opcodeg(char *str);
int intcheck(char *str);
void push(stack_t **stack, unsigned int line_n);
void pall(stack_t **stack, unsigned int line_n);
void stack(stack_t **stack, unsigned int line_n);
void queue(stack_t **stack, unsigned int line_n);
void freeline(char *line);
void pint(stack_t **stack, unsigned int line_n);
#endif

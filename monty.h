#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
}
stack_t;
void execute_monty(FILE *file);
void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
int is_numeric(const char *str);
#endif /* MONTY_H */


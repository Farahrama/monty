#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
void execute_monty(FILE *file) {
int value;
char *line = NULL;
size_t len = 0;
ssize_t read;
stack_t *stack = NULL;
unsigned int line_number = 1;
while ((read = getline(&line, &len, file)) != -1) {
char *opcode = strtok(line, " \t\n");
if (opcode == NULL)
continue;
if (strcmp(opcode, "push") == 0) {
char *value_str = strtok(NULL, " \t\n");
if (value_str == NULL || !is_numeric(value_str))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(line);
exit(EXIT_FAILURE);
}
value = atoi(value_str);
push(&stack, value);
}
else if (strcmp(opcode, "pall") == 0) {
pall(&stack, line_number);
} 
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
free(line);
exit(EXIT_FAILURE);
}
line_number++;
}
free(line);
}
int is_numeric(const char *str) {
if (str == NULL || *str == '\0')
return 0;
if (*str == '-' || *str == '+')
str++;
while (*str) {
if (*str < '0' || *str > '9')
return 0;
str++;
}
return 1;
}


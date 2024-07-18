#include "monty.h"
/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 *
 * Description:
 * - Allocates a new node and stores the given value in it.
 * - Updates pointers to maintain the stack structure.
 * - Prints an error and exits with EXIT_FAILURE if malloc fails.
*/
void push(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
*stack = new_node;
if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
}
/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number where the instruction is found (unused)
 *
 * Description:
 * - Traverses the stack from the head and prints each element's value.
 * - If the stack is empty, it does nothing.
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current;
(void)line_number;
current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

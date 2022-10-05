#include "monty.h"

/**
 * add_new_node - adds a node to a stack
 * @number: number value of the stack
 * Return: nothing
 */
stack_t *add_new_node(int number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	new_node->n = no;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * monty_push - pushes an element to the stack
 * @stack: a double pointer to the stack
 * @line_number: the line at which this command is called
 * Return: nothing
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *start = stack, *temp;
	int num = atoi(toks_num);
	if (num == 0 && toks_num[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = add_new_node(num);
	start->next = temp;
	temp->prev = start;
	temp->next = NULL;
	start = temp;
}

/**
 * monty_pall - prints all the values on the stack, starting
 * from the top of the stack
 * @stack: a double pointer to the stack
 * @line_number: the line at which this command is called
 * Return: nothing
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * monty_pint -  prints the value at the top of the stack,
 * followed by a new line
 * @stack: a double pointer to the stack
 * @line_number: the line at which this command is called
 * Return: nothing
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * free_stack - frees a stack
 * @stack: the stack to free
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack, *previous = *stack;
	while (temp)
	{
		temp = temp->next;
		free(previous);
	}
	stack = NULL;
}

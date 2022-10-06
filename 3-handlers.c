#include "monty.h"


/**
 * push_handler - pushes an element to the stack
 * @stack: a double pointer to the stack
 * @line_number: the line at which this command is called
 */
void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack, *temp;
	int num;

	if (!(global.toks_num) || is_digit(global.toks_num) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		global.err_status = EXIT_FAILURE;
		return;
	}
	num = atoi(global.toks_num);
	new = add_new_node(num);

	if (check_mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		new->prev = *stack;
		new->next = temp;
		if (temp)
			temp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new->prev = temp;
		new->next = NULL;
		temp->next = new;
	}
}

/**
 * pall_handler - prints all the values on the stack, starting
 * from the top of the stack
 * @stack: a double pointer to the stack
 * @line_number: the line at which this command is called
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint_handler -  prints the value at the top of the stack,
 * followed by a new line
 * @stack: a double pointer to the stack
 * @line_number: the line at which this command is called
 */
void pint_handler(stack_t **stack, unsigned int line_number)
{
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		global.err_status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

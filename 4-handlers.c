#include "monty.h"


/**
 * pop_handler - a function that removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: the line number where the pop command is called
 *
 * Return: nothing
 */
void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack)->next)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		global.err_status = EXIT_FAILURE;
		return;
	}
	temp = (*stack)->next->next;
	free((*stack)->next);
	if (temp)
		temp->prev = *stack;

	(*stack)->next = temp;
}

/**
 * swap_handler - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void swap_handler(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = (*stack)->next;
	int stack_len;

	stack_len = stack_size((*stack)->next);
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}
	temp = temp->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}

/**
 * add_handler - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void add_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;

	pop_handler(stack, line_no);
}

/**
 * sub_handler - subtracts the top element of the stack
 *				from the second top element
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void sub_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;

	pop_handler(stack, line_no);
}

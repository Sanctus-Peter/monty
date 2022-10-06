#include "monty.h"

/**
 * div_handler - divides the second top element of the
 * stack by the top element of the stack
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void div_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}
	if (!(*stack)->next->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;

	pop_handler(stack, line_no);
}

/**
 * mul_handler - multiplies the second top element of the stack with
 * the top element of the stack
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void mul_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;

	pop_handler(stack, line_no);
}

/**
 * mod_handler - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void mod_handler(stack_t **stack, unsigned int line_no)
{
	int size = stack_size((*stack)->next);

	if (size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}
	if (!(*stack)->next->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_handler(stack, line_no);
}

/**
 * pchar_handler -  prints the char at the top of the stack,
 * followed by a new line
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void pchar_handler(stack_t **stack, unsigned int line_no)
{
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
		global.err_status = EXIT_FAILURE;
		return;
	}

	printf("%c\n", (*stack)->next->n);
}


/**
 * pstr_handler - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}

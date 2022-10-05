#include "monty.h"

/**
 * monty_div - divides the second top element of the
 * stack by the top element of the stack
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void monty_div(stack_t **stack, unsigned int line_no)
{
	int dividend, size;
	stack_t *temp = *stack;

	size = stack_size(*stack);
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (!(temp->n))
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}
	dividend = temp->prev->n / temp->n;
	temp->prev->n = dividend;
	*stack = temp->prev;
	(*stack)->next = NULL;
	temp->prev = NULL;
	free(temp);
}

/**
 * monty_mul - multiplies the second top element of the stack with
 * the top element of the stack
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void monty_mul(stack_t **stack, unsigned int line_no)
{
	int product, size;
	stack_t *temp = *stack;

	size = stack_size(*stack);
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	product = temp->prev->n * temp->n;
	temp->prev->n = product;
	*stack = temp->prev;
	(*stack)->next = NULL;
	temp->prev = NULL;
	free(temp);
}

/**
 * monty_mod - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void monty_mod(stack_t **stack, unsigned int line_no)
{
	int remainder, size;
	stack_t *temp = *stack;

	size = stack_size(*stack);
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (!temp->n)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}
	remainder = temp->prev->n % temp->n;
	temp->prev->n = remainder;
	*stack = temp->prev;
	(*stack)->next = NULL;
	temp->prev = NULL;
	free(temp);
}

/**
 * monty_pchar -  prints the char at the top of the stack,
 * followed by a new line
 * @stack: double pointer to the stack
 * @line_no: the line in which this command is called
 * Return: nothing
 */
void monty_pchar(stack_t **stack, unsigned int line_no)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}


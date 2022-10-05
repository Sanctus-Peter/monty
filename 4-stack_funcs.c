#include "monty.h"
/**
 * pop - a function that removes the top element of the stack
 * @stack: double pointer to the stack
 * line_number: the line number where the pop command is called
 * Return : nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack))
	{
		fprintf(stderr,"L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->prev;
	temp->prev->next = NULL;
	temp->prev = NULL;
	free(temp);
}

/**
 * stack_size - gets the size of a stack
 * @stack: pointer to the stack
 * Return: the size
 */
int stack_size(stack_t *stack)
{
	int i = 0;
	stack_t *temp = stack;

	while (temp != NULL)
	{
		i++;
		temp = temp->prev;
	}
	return (i);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = *stack;
	int i, buffer;

	i = stack_size(*stack);
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	buffer = (*stack)->prev->n;
	(*stack)->prev->n = temp->n;
	temp->n = buffer;
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_no)
{
	int size, sum;
	stack_t *temp = *stack;

	size = stack_size(*stack);
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	sum = temp->n + temp->prev->n;
	temp->prev->n = buffer;
	*stack = temp->prev;
	*stack->next = NULL;
	temp->prev = NULL;
	free(temp);
}

/**
 * sub - subtracts the top element of the stack from the second
 top element
 * @stack: double pointer to the stack
 * @line_no: the line number where the pop command is called
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_no)
{
	int size, diff;
	stack_t *temp = *stack;

	size = stack_size(*stack);
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	diff = temp->n - temp->prev->n;
	temp->prev->n = diff;
	*stack = temp->prev;
	*stack->next = NULL;
	temp->prev = NULL;
	free(temp);
}

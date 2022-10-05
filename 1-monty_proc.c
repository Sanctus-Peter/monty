#include "monty.h"

/**
 * stack_init - initialize an empty stack
 * 
 * Return: pointer to the new stack
 */
stack_t *stack_init(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = STACK;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}

/**
 * get_op_func - matches an operation with its corresponding function
 * @ops: the operation to be match
 *
 * Return: A pointer to the corresponding function
 */
void (*get_op_func(char *ops))(stack_t **, unsigned int)
{
	instruction_t func[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i = 0;
	while (func[i].opcode)
		if (strcmp(ops, func[i++].opcode) == 0)
			return (func[--i].f);

	return (NULL);
}

/**
 * exec_monty - function to execute a monty bytecodes script
 * @line_fd: file descriptor for an open Monty bytecodes script
 *
 * Return: EXIT_SUCCESS on success,EXIT_FAILURE otherwise
 */
int exec_monty(FILE *line_fd)
{
	stack_t *stack = NULL;
	char *line_read = NULL, *toks_str = NULL;
	size_t len = 0, exit_val = EXIT_SUCCESS;
	unsigned int line_num = 0;
	void (*op_func)(stack_t**, unsigned int);

	stack = stack_init();

	while (getline(&line_read, &len, line_fd) != -1)
	{
		line_num++;
		if (*line_read == '\n')
			continue;

		toks_str = strtok(line_read, DELIM);
		
		if (!toks_str || *toks_str == '#')
			continue;
		
		toks_num = strtok(NULL, DELIM);
		
		op_func = get_op_func(toks_str);
		if (!op_func)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_num, toks_str);
			exit_val = EXIT_FAILURE;
			break;
		}

		op_func(&stack, line_num);

	}
	free_stack(&stack);
	free(line_read);
	free(toks_num);
	free(toks_str);

	return (exit_val);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (1).
 *         If the stack_t is in queue mode - QUEUE (0).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

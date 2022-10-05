#include "monty.h"

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


void (*get_op_func(char *ops))(stack_t **, unsigned int)
{
	instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap",swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i = 0;
	while (func[i].opcode)
		if (strcmp(ops, func[i++].opcode) == 0)
			return (func[--i].f);

	return (NULL);
}


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
	}
}

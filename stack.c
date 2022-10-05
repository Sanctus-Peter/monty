#include "monty.h"

stack_t *add_new_node(int no)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{

	}
	new_node->n = no;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void free_stack(stack_t *start)
{
	stack_t *temp, previous = start, start;
	while (temp)
	{
		temp = temp->next;
		free(previous);
	}
}

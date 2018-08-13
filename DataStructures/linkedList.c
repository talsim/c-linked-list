#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

// Create a node to add to a list from a given value val
static Node* create_node(int);

List* create_list()
{
	List *ans = (List*)malloc(sizeof(List));
	ans->size = 0;
	ans->start = NULL;
	ans->end = NULL;
	return ans;
}

void add_last(List *self, int val)
{
	Node *to_add = create_node(val);
	if (self->size == 0)
	{
		self->start = to_add;
		self->end = to_add;
	}
	else
	{
		self->end->next = to_add;
		self->end = to_add;
	}
	self->size++;
}

void print_list(List *self)
{
	Node *curr = self->start;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

void free_list(List *self)
{
	Node *curr = self->start;
	List *tmp;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

static Node* create_node(int val)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}
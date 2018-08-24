#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create a node to add to a list from a given value val
static Node* create_node(int);
// gets a value and return's its node
static Node* get_node_by_value(List*, int);

List* create_list()
{
	List *ans = (List*)malloc(sizeof(List));
	ans->size = 0;
	ans->start = NULL;
	ans->end = NULL;
	return ans;
}

void add_first(List *self, int val)
{
	Node *add = create_node(val);
	if (self->size == 0)
	{
		self->start = add;
		self->end = add;
	}
	else
	{
		add->next = self->start;
		self->start = add;
	}
	self->size++;
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

void print_list(List *self) // prints until the next NULL
{
	printf("[");
	if (!is_empty(self))
	{
		Node *curr = self->start;
		while (curr != NULL)
		{
			if (curr == self->end)
				printf("%d", curr->data);
			else
				printf("%d, ", curr->data);
			curr = curr->next;
		}
	}
	printf("]\n");
}

void free_list(List *self)
{
	Node *curr = self->start;
	Node *tmp = NULL;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}

int get_first(List *self)
{
	Node *first = self->start;
	if (first != NULL)
		return first->data;
	else
	{
		fprintf(stderr, "Error: The first node is empty!\n");
		exit(1);
	}
}

int get_last(List *self)
{
	Node *last = self->end;
	if (last != NULL)
		return last->data;
	else
	{
		fprintf(stderr, "Error: The last node is empty!\n");
		exit(1);
	}
}

int get(List *self, int index)
{
	if (index > self->size) // out of bounds
	{
		fprintf(stderr, "linked list out of bounds!\n");
		return NULL;
	}
	int count = 0;
	Node *curr = self->start;
	while (curr != NULL)
	{
		if (count == index)
			return curr->data;
		count++;
		curr = curr->next;
	}
}

void remove_first(List *self)
{
	if (is_empty(self) == true)
		fprintf(stderr, "Error: the list is empty!\n");
	Node *tmp = self->start;
	if (tmp != NULL)
	{
		self->start = self->start->next;
		free(tmp);
	}
	self->size--;
}

void remove_last(List *self)
{
	if (is_empty(self) == true)
		fprintf(stderr, "Error: the list is empty!\n");
	Node* curr = NULL;
	Node *tmp = self->end;
	for (curr = self->start; curr->next != self->end; curr = curr->next); // find the node before end
	self->end = curr;
	self->end->next = NULL;
	free(tmp);
	self->size--;
}

void remove_by_value(List *self, int val)
{
	// check if the list is empty
	if (is_empty(self) == true)
		fprintf(stderr, "Error: the list is empty!\n");

	// check if the value is in the list
	else if (contains(self, val) == false)
	{
		fprintf(stderr, "Error: The value %d isn't in the list!\n", val);
		exit(1);
	}

	// go through the list and take care of all the cases
	if (self->start->data == val) // case its the first node
	{
		remove_first(self);
	}

	else if (self->end->data == val) // case its the last node
	{
		remove_last(self);
	}

	else // case its not end or start
	{
		Node *remove = get_node_by_value(self, val);
		Node *bef_remove = NULL;
		for (bef_remove = self->start->next; bef_remove->next != remove; bef_remove = bef_remove->next); // puting bef_remove location 1 before remove
		bef_remove->next = remove->next; // linking the node before remove to the node after remove
		free(remove); //freeing remove
	}
}

int contains(List *self, int val) // search for a val in the list
{
	return get_node_by_value(self, val);
}

int is_empty(List *self)
{
	return (self->size == 0);
}

List* reverse(List *self)
{
	Node *prev = NULL;
	Node *curr = self->start;
	Node *next;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	self->start = prev;
	self->end = NULL;
	return self;
}

List* clone(List *self)
{
	// check if self is null
	if (is_empty(self))
		return NULL;

	// create new list
	List *new_list = (List*)malloc(sizeof(List));
	new_list->start = create_node(self->start->data);

	// nodes for iteartion
	Node *curr_node = self->start;
	Node *prev_new_node = new_list->start;
	Node *next_new_node = prev_new_node->next; // NULL

	while (curr_node->next != NULL)
	{
		// copy data
		next_new_node = create_node(curr_node->next->data);
		prev_new_node->next = next_new_node;

		// go to next
		prev_new_node = prev_new_node->next;
		curr_node = curr_node->next;
	}
	// update new list -> end
	new_list->end = next_new_node;

	// update new list -> size
	new_list->size = self->size;

	// return new list
	return new_list;
}

static Node* get_node_by_value(List *self, int val)
{
	Node* curr = self->start;
	while (curr != NULL)
	{
		if (curr->data == val)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

static Node* create_node(int val)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}
typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct List
{
	Node *start;
	Node *end;
	int size;
} List;

List* create_list();
void add_first(List*, int);
void add_last(List*, int);
void remove_first(List*);
void remove_last(List*);
void print_list(List*);
void free_list(List*);
int get_first(List*);
int get_last(List*);
int is_empty(List*);
List* reverse(List*);
List* clone(List*);

// add(index)
// remove_first
// remove_last
// remove(index)
// get(index)
// contains(val)

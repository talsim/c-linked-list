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
void add_last(List*, int);
void print_list(List*);
void free_list(List*);
int get_first(List*);
int get_last(List*);
int is_empty(List*);
List* reverse(List*);
List* clone(List*);
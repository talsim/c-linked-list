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
void add_first(List *self, int val);
void add_last(List *self, int val);
void add_before_index(List *self, int index, int val);
void remove_first(List *self);
void remove_last(List *self);
void remove_by_value(List *self, int val);
void print_list(List *self);
void free_list(List *self);
int contains(List *self, int val);
int get_first(List *self);
int get_last(List *self);
int get(List *self, int index);
int is_empty(List *self);
List* reverse(List *self);
List* clone(List *self);


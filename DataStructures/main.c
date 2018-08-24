#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_first(lst, 1);
	add_last(lst, 2);
	add_last(lst, 3);
	print_list(lst);
	free_list(lst);
	return 0;
}
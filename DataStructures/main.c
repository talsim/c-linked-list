#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_first(lst, 1);
	add_first(lst, 2);
	add_last(lst, 3);
	add_last(lst, 4);
	add_last(lst, 5);
	remove_by_value(lst, 3);
	print_list(lst);
	free_list(lst);
	return 0;
}
#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_first(lst, 1);
	add_last(lst, 2);
	add_last(lst, 3);
	add_last(lst, 4);
	add_last(lst, 5);
	add_last(lst, 6);
	add_last(lst, 7);
	add_last(lst, 8);
	remove_by_value(lst, 8);
	print_list(lst);
	free_list(lst);
	return 0;
}
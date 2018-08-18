#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_first(lst, 2);
	add_last(lst, 3);
	add_last(lst, 4);
	remove_first(lst);
	print_list(lst);
	free_list(lst);
	return 0;
}
#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_last(lst, 5);
	add_last(lst, 0);
	add_last(lst, 3);
	List *lst2 = clone(lst);
	print_list(lst2);
	free_list(lst);
	free_list(lst2);
	return 0;
}
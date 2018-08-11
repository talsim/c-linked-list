#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_last(lst, 5);
	add_last(lst, 0);
	add_last(lst, 3);
	print_list(lst);
	return 0;
}
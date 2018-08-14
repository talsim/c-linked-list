#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_last(lst, 5);
	add_last(lst, 0);
	add_last(lst, 3);
	List *reversed = reverse(lst);
	print_list(reversed);
	free_list(reversed);
	return 0;
}
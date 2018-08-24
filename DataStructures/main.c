#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_first(lst, 88888);
	add_last(lst, 203);
	add_last(lst, 646);
	add_last(lst, 6488);
	add_last(lst, 649);
	add_last(lst, 6496);
	add_last(lst, 642);
	add_before_index(lst, 7, 5);
	print_list(lst);
	free_list(lst);
	return 0;
}
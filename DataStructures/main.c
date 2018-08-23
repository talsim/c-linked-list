#include "linkedList.h"

int main()
{
	List *lst = create_list();
	add_first(lst, 1);
	add_last(lst, 2);
	add_last(lst, 3);
	int check = get(lst, 5);
	printf("val: %d\n", check);
	print_list(lst);
	free_list(lst);
	return 0;
}
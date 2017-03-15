#include <stdio.h>

#include "sll.h"

int main(int argc, char *argv[])
{
	int i;
	struct node *sl = NULL;

	sll_insert_nth(&sl, 1, 1111);
	sll_print(sl);

	for (i = 0; i < 10; i++)
		sll_append(&sl, i * 10);

	sll_print(sl);
    sll_insert_nth(&sl, 13, 55);
	sll_print(sl);
	sll_delete_rec(sl);
	return 0;
}

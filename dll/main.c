#include <stdio.h>

#include "dll.h"

int main(int argc, char *argv[])
{
	int i;
	struct node *sl = NULL;

	for (i = 0; i < 10; i++)
		dll_append(&sl, i * 10);

	dll_print(sl);
	dll_delete(&sl);

	dll_print(sl);
	return 0;
}

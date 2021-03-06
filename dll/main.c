#include <stdio.h>

#include "dll.h"

int main(int argc, char *argv[])
{
	int i;
	struct node *sla = NULL;
    struct node *slb = NULL;

	for (i = 1; i <= 10; i++) {
		dll_insert_nth(&sla, i, i * 10);
		dll_print(sla);
	}

	for (i = 0; i < 5; i++)
		dll_append(&slb, i * 100);

	dll_print(sla);
	dll_print(slb);
	dll_append_list(&sla, &slb);
	dll_print(sla);
	for (i = 0; i < 15; i++) {
		dll_delete_nth(&sla, 1);
		dll_print(sla);
	}
	dll_delete(&sla);

	return 0;
}
